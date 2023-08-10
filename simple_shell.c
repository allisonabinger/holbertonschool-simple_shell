#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - Entry point
 *
 * Return: always 0 (success)
 */

int main()
{
	char *line;
	size_t bufsize = 0;
	ssize_t chars_read = 0;
	char **cmdtoks;
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
				launch_process(cmdtoks);
			}
			free_args(cmdtoks);
		}
		free(line);
	}
	return (0);
}
