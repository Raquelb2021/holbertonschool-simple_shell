#ifndef SHELLHEADER_H
#define SHELLHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>



int exec_shell(char **args);
char *read_line_shell(void);
char **split_line(char *line);
<<<<<<< HEAD
int dash_exit(char **args);

=======
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv);
>>>>>>> ccbfe4347fd8d4d8bc19d2bf466ceac3afe8356d
#endif
