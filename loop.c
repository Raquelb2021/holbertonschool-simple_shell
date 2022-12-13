#include "shellheader.h"
/**
 * main - print a prompt
 * Return: 0
 * @argc: void
 * @argv: void
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *line;
	char **tokens;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
		}

		line = read_line_shell();

		if (line == NULL)
		{
			exit(0);
		}

		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			exec_shell(tokens);
		}


		free(tokens);
		free(line);

	}
	return (0);
}
