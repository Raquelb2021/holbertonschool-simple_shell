#include "shellheader.h"

/*Exit the shell*/
void kash_exit(char **args)
{
    exit(0);
}
/*Change the working directory*/
void kash_cd(char **args)
{
	    if (args[1] == NULL)
	    {
            fprintf(stderr, "kash: cd: missing argument\n");
        }
	    else
	    {
	        if (chdir(args[1]) != 0)
		{
			perror("kash: cd");
								            }
						    }
}
/*Print the shell's help text*/
void kash_help(char **args)
{
	    char *helptext =
            "Kash - the Kinda Aimless Shell. "
            "The following commands are built in:\n"
            "  cd       Change the working directory.\n"
            "  exit     Exit the shell.\n"
	           "  help     Print this help text.\n"
	           ;
	       printf("%s", helptext);
}
/*A builtin instance associates a command name with a handler function.*/

struct builtin
{
	char *name;
        void (*func)(char **args);
         };
/*Array of built in commands.*/

struct builtin builtins[] = 
{
	    {"help", kash_help},
	        {"exit", kash_exit},
		    {"cd", kash_cd},
};
/*Returns the number of registered commands.*/

int kash_num_builtins()
{
    return sizeof(builtins) / sizeof(struct builtin);
}
/**
 * kash_exec - execute command
 * @args:  character
 *
 */
void kash_exec(char **args)
{

	int i;

	for (i = 0; i < kash_num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("kash");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;

		do

		{
			waitpid(child_pid, &status, WUNTRACED);
		}
		while
			(!WIFEXITED(status) && !WIFSIGNALED(status));
	}


	else
		{
		perror("kash");
		}
}
