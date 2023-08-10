#include "shell.h"
#include <unistd.h>
/**
 * launch_process - forks a process to execute an external cmd
 *
 * @cmd: tokenized arguments
 *
 * Return: NULL
 */
void launch_process(char **cmd)
{
	pid_t kidpid;
/**	int status; <----what's this? */
	char *cmdstr = NULL;
	char *argv[2] = {NULL, NULL};

	strcpy(cmdstr, *cmd);
	argv[0] = cmdstr;
	argv[1] = NULL;
	kidpid = fork();

	if(kidpid < 0)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	else if (kidpid == 0)
	{
		execve(cmdstr, argv, NULL); /**parameters must have full path*/
	}
}
