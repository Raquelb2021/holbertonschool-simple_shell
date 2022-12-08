#ifndef SHELLHEADER_H
#define SHELLHEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);

#endif
