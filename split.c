#include "shellheader.h"
/**
 * split_line - We use the strtok() to split the string on instances
 * of whitespace.
 * @line: the string
 * Return: tokens
 */
char **split_line(char *line)
{
	int length = 0;
	int capacity = 32;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimeters = " \n";
	char *token = strtok(line, delimeters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		token = strtok(NULL, delimeters);
	}
	tokens[length] = NULL;
	return (tokens);
}
