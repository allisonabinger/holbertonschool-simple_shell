#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
/**
 * main - entry point
 * Return: always 0 (success)
 */
int main() /** add argc and argv and use them somewhere */
{
	char *line;
	char **commands;

	while (1) 
	{
		printf("$ ");
		line = read_line();
		if (line != NULL)
		{
			printf("attempting parse_line...");
			commands = parse_line(line);
			printf("parse_line success!");
			if (commands != NULL)
			{
/**	implement pls			exec_cmd(commands); */
			}
		}
		printf("attempting free(line)...");
		free(line);
		printf("free(line) success!");
/**	implement pls	free_args(commands); */
	}
}
