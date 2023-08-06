#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - Entry point, idle wait function
 * @argc: number of args
 * @argv: array of strings passed
 * @env: array of strings passed as an environment
 * Return: 0 (Always success)
 */
int main(int agrc, char **argv, char **env)
{
	char* input;
	char** arguments;
	int arg_count;
	int background;

	while (1)
	{
		//displays prompt and read user input
		printf("> ");
		input = read_input();

		//tokenizes input
		arguments = token_arg(input, &arg_count);

		//check for built-in
		if (!find_cmd(arguments, arg_count))
		{
			//if not a built-in, execute the external command
			if (!exec_cmd(arguments, arg_count))
			{
				//if command isn't found, try to resolve path
				char* resolved_path = resolved_path(arguments[0]);
				if (resolved_path != NULL)
				{
					free(arguments[0]);
					arguments[0] = resolved_path;

					if (!exec_cmd(arguments, arg_count))
					{
						printf("Command not found");
					}
				}
				else
					printf("Command not found");
			}
		}
		free_args(arguments, arg_count);

		free(input);
	}
	return (0);
}
