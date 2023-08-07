#ifndef SHELL_H
#define SHELL_H

#include <string.h>

#define INPUT_LENGTH 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

// starts the shell and enters main loop //
void shell_login();

// reads line of input from user, returns string //
char *read_line();

// parses input line into individual comamnds (tokenizer) //
char **parse_line(char *line);

// executes parsed command //
void exec_cmd(char **commands);

// handles built-ins //
void exec_bi_cmd(char **args);

// launches process for non-built-in commands //
void launch_process(char **args);

// handles signals //
void handle_signal(int signal);

//free the memory allocated for the command arguments //
void free_args(char **args);

//handle errors //
void handle_error();

#endif
