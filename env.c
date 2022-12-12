#include "shellheader.h"
/**
 * main - prints the current environment
 * Return: return 0 if success
 * @argc: unused argument count
 * @argv: unused argument vector
 * @envp: third parameter is an array of pointers to environment variables
 */
int main(__attribute__((unused))int argc, char **argv, char **envp)
{

	char **env;

	for (env = envp; *env != 0; env++)
	{
		char *thisEnv = *env;

		printf("%s\n", thisEnv);
	}
	return (0);
}
