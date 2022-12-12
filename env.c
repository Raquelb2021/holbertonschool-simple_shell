#include "shellheader.h"
/**
 * main - prints the current environment
 * Return: return 0 if success
 */
int main(void)
{
	printf("USER = %s\n", getenv("USER"));
	printf("LANGUAGE = %s\n", getenv("LANGUAGE"));
	printf("SESSION = %s\n", getenv("SESSION"));
	printf("COMPIZ_CONFIG_PROFILE = %s\n", getenv("COMPIZ_CONFIG_PROFILE"));
	printf("SHLVL = %s\n", getenv("SHLVL"));
	printf("PATH = %s\n", getenv("PATH"));
	return (0);
}
