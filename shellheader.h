#ifndef SHELLHEADER_H
#define SHELLHEADER_H


#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

void shell_exec(char **args);
char **shell_split_line(char *line);
char *shell_read_line();
void shell_loop(void);


#endif
