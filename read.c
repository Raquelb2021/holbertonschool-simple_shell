#include "shellheader.h"
/**
 * shell_read_line - read commands from a text file
 * Return: line
 */
char *shell_read_line()
{
	    char *line = NULL;
	    size_t buflen = 0;

	    getline(&line, &buflen, stdin);

	return (line);
}
