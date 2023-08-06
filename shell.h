#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>

int main(int argc, char **argv, char **env);
//displays prompt, reads input from user and passes to next function

char* read_input();
//reads line of input and returns input as a strings passses to token_arg

char **token_arg(char *input, int arg_count);
//tokenizes input string into arguments and returns array of strings

int *check_built_in(char **arguments);
//checks to see if the function is built in or should be forked.

int *execute_cmd(char **arguments, int arg_count);
//forks and uses child process to execve and execute command

int *check_io(char **arguments, int arg_count);
//handles input/output redirection if > or >> is found. 

char *resolve_path(char *command);
//takes string of command and returns the full path

int *check_bg_fg(char **arguments, int arg_count);
//checks for & to determine fore/background commands. returns 0 if fg, 1 if bg

int *exec_bg_cmd(char **arguments, int arg_count);
//executes commands in the background.

void free_arg(char **arguments, int arg_count);
//frees memory allocated for arguments.

int check_pipes(char **arguments, int arg_count);
//handles piping if | is found. 

void check_signal();
//unsure of prototype here.

int main(int argc, char *argv[]);
//entry point, loop to keep shell running continuously.
