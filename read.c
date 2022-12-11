#include "shellheader.h"
/**
 * read_line_shell - read line from the user
 * Return: line
 */
char *read_line_shell(void)
{
	char *line = NULL;
	size_t buflen = 0;
	int temp;

	temp = getline(&line, &buflen, stdin);
	if (temp == EOF)
	{
		free(line);
		exit(0);
	}
	return (line);
}
