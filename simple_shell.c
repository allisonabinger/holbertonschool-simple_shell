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
		printf("attempting to read line...\n");
		line = read_line();
		printf("read line success!\n");
		if (line != NULL)
		{
			printf("attempting parse_line...i\n");
			commands = parse_line(line);
			printf("parse_line success!\n");
			if (commands != NULL)
			{
/**	implement pls			exec_cmd(commands); */
			}
		}
		printf("attempting free(line)...\n");
		free(line);
		printf("free(line) success!\n");
/**	implement pls	free_args(commands); */
	}
}
