#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main(void)
{
	char *line, **cmdtoks;
	size_t bufsize = 0;
	ssize_t chars_read = 0;
	int bicmd;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("$ ");

		chars_read = getline(&line, &bufsize, stdin);
		if (chars_read < 0)
		{
			free(line);
			continue;
		}

		cmdtoks = tokenizer(line, TOKEN_DELIMETERS);

		if (cmdtoks != NULL)
		{
			bicmd = exec_cmd(cmdtoks);

			if (bicmd != 0)
			{
				char *env_path = getenv("PATH");
				char command_with_path[80];
				strcpy(command_with_path, env_path);
				strcat(command_with_path, "/");
				strcat(command_with_path, cmdtoks[0]);

				pid_t pid = fork();

				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					execve(command_with_path, cmdtoks, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
				{
					int status;
					waitpid(pid, &status, 0);
					if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
						fprintf(stderr, "Command execution failed\n");
				}
			}
			free_args(cmdtoks);
		}
		free(line);
	}
	return (0);
}

