#include "shell.h"
/**
 * launch_process - launches process using fork and execve
 * @cmdtoks: command to execute
 */
void launch_process(char **cmdtoks)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		/* Check if the command has execute permissions */
		if (access(cmdtoks[0], X_OK) == -1)
		{
			perror("access");
			free(cmdtoks);
			exit(EXIT_FAILURE);
		}

		if (execve(cmdtoks[0], cmdtoks, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				return;
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
