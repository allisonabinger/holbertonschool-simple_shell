#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * read_line - Reads user input from the command line
 *
 * Return: lineptr (the user input) on [SUCCESS]
 */

char *read_line(void)
{
	char *lineptr = NULL; /** buffer that holds user input as 1 string */
	size_t n; /** max size of acceptable inputs */

	n = INPUT_LENGTH;	

	lineptr = malloc(sizeof(n));

	if (lineptr == NULL); /** Error handling for malloc() failure */
	{
		perror("Not enough memory to malloc()");
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	if ((getline(&lineptr, &n, stdin)) < 0) /** Error handling for getline() failure */
	{
		perror("Could not read line");
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	
	return (lineptr);
}
