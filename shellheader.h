#ifndef SHELLHEADER_H
#define SHELLHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void exec_shell(char **args);
char *read_line_shell(void);
char **split_line(char *line);
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv);
#endif
