#include "shellheader.h"
/**
 * exec_shell - create a child and use the exec()
 * We use the strtok() function from <string.h> to split the string on
 * instances of whitespace.
 * @args: arguments
 */
int exec_shell(char **args)
{
	pid_t cpid;
	int status;

	if (strcmp(args[0], "exit") == 0)
	{
		 return dash_exit(args);
	}

	cpid = fork();

	if (cpid == 0)
	{
		if (execvp(args[0], args) < 0)
		printf("command not found: %s\n", args[0]);
		exit(EXIT_FAILURE);

	}
	else if (cpid < 0)
		printf("Error forking\n");

	else
	{
		waitpid(cpid, & status, WUNTRACED);

	}
	return (1);
}
