#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
/**
 * main - entry point
 * Return: always 0 (success)
 */
int main()
{
	char *line;
	size_t bufsize = 0;
	ssize_t chars_read = 0;
	char **cmdtoks;

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

		if (cmdtoks == NULL)
		{
			/**implementless
			 * free_arg(cmdtoks);
			 * continu:
			 */
		}
		/**
		 * need to write
		 * exec_cmd(cmdtoks);
		 */

		free(line);
		/**
		 * need to write
		 * free_args(cmdtoks);
		 */
	}
}
