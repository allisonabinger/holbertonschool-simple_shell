#include <stdio.h>
#include <stdlib.h>
#include <string,h>
#include "shell.h"
/**
 * main - entry point
 * Return: always 0 (success)
 */
int main()
{
	start_shell();
	return (0);
}

void start_shell()
{
	char *line;
	char **commands;

	while (1)
	{
		printf("> ");
		line = read_line();
		commands = parse_line(line);
		exec_cmd(commands);

		free(line);
		free_args(commands);
	}
}
