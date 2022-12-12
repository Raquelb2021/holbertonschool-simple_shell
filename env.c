#include "shellheader.h"
/**
 * main - prints the current environment
 * Return: return 0 if success
 */
int main(void)
{
	char **s = environ;

	for (; *s; s++)
	{
		printf("%s\n", *s);
	}

	return (0);
}
