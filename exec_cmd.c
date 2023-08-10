#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * exec_cmd - Determines if the command is a built-in command
 * or calls launch_process to execute it if not.
 * @cmd: Command passed from the user.
 * Return: 0 if a built-in command was executed, 1 if the command is not
 */
int exec_cmd(char **cmd)
{
	if (strcmp(*cmd, "cd") == 0)
	{
		if (cmd[1] != NULL)
		{
			const char *homedir = cmd[1];

			if (chdir(homedir) != 0)
			{
				perror("cd");
			}
		}
		else
		{
			fprintf(stderr, "cd: missing operand\n");
		}
		return (0);
	}
	else if (strcmp(*cmd, "exit") == 0)
	{
		exit(0);
	}
	else
		return (1);
}
