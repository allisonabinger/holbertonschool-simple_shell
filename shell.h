#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define TOKEN_DELIMETERS " \t\r\n\a"

/* Function prototypes */
void pathfinder(char **cmdtoks);
void launch_process(char **cmdtoks);
char **tokenizer(char *line, const char *delimiters);
int exec_cmd(char **cmdtoks);
void free_args(char **args);

#endif /* SHELL_H */
