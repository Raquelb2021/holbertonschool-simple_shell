#include "shellheader.h"
/**
 * shell_loop - print a prompt
 *
 */
void shell_loop(void)
{
	char *line;
	char **tokens;

	while (true)
	{
		printf("$ ");
		line = shell_read_line();
		tokens = shell_split_line(line);

	if (tokens[0] != NULL)
	{
		shell_exec(tokens);
	}
		free(tokens);
		free(line);
	}
}
