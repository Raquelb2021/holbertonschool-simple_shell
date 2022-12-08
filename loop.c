#include "shellheader.h"
/**
 * shell_loop - print a prompt
 *
 */
int main(int ac, char **argv)
{
	char *full_command = NULL, *copy_command = NULL;
	size_t n = 0;
	ssize_t chars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	printf("$ ");

	/*declaring void variables*/
	(void)ac;

	/* get the string that the user types in and pass it to full_command */
	chars_read = getline(&full_command, &n, stdin);
	
	/* let's allocate space to store the characters read by getline */
	copy_command = malloc(sizeof(char) * chars_read);

	if (copy_command == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}

	/* make a copy of the command that was typed */
	strcpy(copy_command, full_command);

	/* check if the getline function failed or reached EOF or user use CTRL + D */

		if (chars_read== -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}
	else
	{

	/* split the string (full_command) into an array of words */
		token = strtok(full_command, delim);

	/* allocate space to store the variable arguments but before then determine how many tokens are there*/
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
	/*printf(">>>> %s \n", num_tokens);*/
	
	/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) *num_tokens);

		/* Store each token in the argv array */
		token = strtok(copy_command, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);


		/*printf(">>>> %s \n", argv[i]);*/
			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		
	/*execute the commands with execve */


	/*free up allocated memory */
	free(argv);
	free(full_command);
	free(copy_command);
	
	}
	return (0);
}
