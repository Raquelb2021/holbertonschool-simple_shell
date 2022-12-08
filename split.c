#include "shellheader.h"
/**
 * shell_split_line - tokenize the string
 * @line: string to be tokenized
 * Return: tokens
 */
char **shell_split_line(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimiters = " \n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

	if (length >= capacity)
	{
		capacity = (int) (capacity * 1.5);
		tokens = realloc(tokens, capacity * sizeof(char *));
	}

	token = strtok(NULL, delimiters);
	}
		tokens[length] = NULL;
		return (tokens);
}
