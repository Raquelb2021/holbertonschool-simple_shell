#include "shellheader.h"

void shell_exit(char **args) {
	(void)args;
	exit(0);
}

struct builtin {
	    char *name;
	        void (*func)(char **args);
};

struct builtin builtins[] = {
	 
	    {"exit", shell_exit},
	      
};
int shell_num_builtins() {
	    return sizeof(builtins) / sizeof(struct builtin);
}
/**
 * exec_shell - create a child and use the exec()
 * We use the strtok() function from <string.h> to split the string on
 * instances of whitespace.
 * @args: arguments
 */
void exec_shell(char **args)
{
	int i;

	pid_t child;

	for (i = 0; i < shell_num_builtins(); i++) {
		if (strcmp(args[0], builtins[i].name) == 0)
			builtins[i].func(args);
		return;
	}

	      child = fork();

	if (child == 0)
	{
		execvp(args[0], args);
		perror("Error1");
		exit(1);

	}
	else if (child > 0)
	{
		int status;

		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	} else {

		perror("Error2");
	}
}
