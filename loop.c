#include "shellheader.h"
/**
 * shell_loop - print a prompt
 *
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr= NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t chars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;


	/*declaring void variables*/
	(void)ac;

	/* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		chars_read = getline(&lineptr, &n, stdin);

	/* check if the getline function failed or reached EOF or user use CTRL + D */

		if (chars_read== -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}

		/* copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

	/* split the string (full_command) into an array of words */
		token = strtok(lineptr, delim);

	/* allocate space to store the variable arguments but before then determine how many tokens are there*/
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
	
	/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) *num_tokens);

		/* Store each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);



			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		
	/*execute the commands with execve */
	execmd(argv);

	/*free up allocated memory */

	free(lineptr_copy);
	free(lineptr);
	
	}
	return (0);
}
