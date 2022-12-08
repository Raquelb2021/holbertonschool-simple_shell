#include "shellheader.h"
/**
 * shell_loop - print a prompt
 *
 */
int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	/*declaring void variables*/
	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
