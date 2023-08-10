#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 64
#define PATH_DELIM ":;"
#define INPUT_LENGTH 1024
#define TOKEN_DELIMETERS " \t\r\n"

/** starts the shell and enters main loop */
int main(void);

/** executes built in or passes to launch_process if not */
int exec_cmd(char **cmd);

/** launches process for non-built-in commands */
void launch_process(char **cmd);

/** tokenizer function */
char **tokenizer(char *line, char *delim);

/** free the memory allocated for the command arguments */
void free_args(char **args);


#endif
