#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * main - entry point
 * Return: always 0 (success)
 */
int main() /** add argc and argv and use them somewhere */
{
	while(1)
	{
		shell_login();
		return (0);
	}
}

void shell_login()
{
	char *line;
	char **commands;

	printf("$ ");
	line = read_line();
	commands = parse_line(line);
	exec_cmd(commands);
	free(line);
	free_args(commands);
}
