#ifndef SHELLHEADER_H
#define SHELLHEADER_H


#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void);
char* kash_read_line();
char** kash_split_line(char *line);
void kash_exec(char **args);
int kash_num_builtins();
void kash_exit(char **args);
void kash_cd(char **args);
void kash_help(char **args);


#endif
