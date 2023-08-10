#include "shell.h"
#include <unistd.h>
#include <stdlib.n>
/**
 * launch_process - forks a process to execute an external cmd
 *
 * @cmd: tokenized arguments
 *
 * Return: NULL
 */
void launch_process(char *cmd)
{
	pid_t kidpid;
	int status;
	kidpid = fork();

	if(kidpid < 0)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	else if (kidpid == 0)
	{
		execve /**parameters must have full path*/
	}
}
