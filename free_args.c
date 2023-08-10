#include "shell.h"

/**
 * <function name goes here> - Entry point
 *
 * <@parameters go here>: Description
 *
 * Return: <insert return value>
 */

void free_args(char **args)
{
	int i = 0;

	for (; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
