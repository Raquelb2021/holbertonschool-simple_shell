#include "shellheader.h"
#include <stdio.h>
#include <stdbool.h>
/**
 * main - read command from the user and it keep on doing so.
 * Split the input into an array of tokens which we interpret
 *as a command and its arguments.
 * Execute the command
 * Return: no return, tipe void
 */
int main(void)
{
	while (true)
	{
		printf("$ ");
		char *line = kash_read_line();
		char **tokens = kash_split_line(line);

		if (tokens[0] != NULL)
		{
			kash_exec(tokens);
		}
		free(tokens);
		free(line);
	}
}
