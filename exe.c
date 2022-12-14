#include "shellheader.h"
/**
 * exec_shell - create a child and use the exec()
 * We use the strtok() function from <string.h> to split the string on
 * instances of whitespace.
 * @args: arguments
 */
void exec_shell(char **args)
{
	pid_t cpid;


	cpid = fork();

	if (cpid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error1");
		exit(1);

	}
	else if (cpid > 0)
	{
		int status;

		wait(&status);
	}
	else
	{
		perror("Error2");
	}
}
