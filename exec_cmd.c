#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * exec_cmd - determines if command is a built-in and executes if so
 * or calls launch_process.
 * @cmd: command passed from user
 * Return: 0 if built-in was executed, 1 if command is not built-in.
 */
int exec_cmd(char **cmd)
{
	if (strcmp(*cmd, "cd") == 0)
	{
		const char *homedir;

		chdir(homedir);
		return (0);
	}
	else if (strcmp(*cmd, "exit") == 0)
		exit(0);
	else
		return (1);
}
