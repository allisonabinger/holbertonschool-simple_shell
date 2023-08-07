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

	if (lineptr == NULL) /** Error handling for malloc() failure */
	{
		printf("Not enough memory to malloc()");
		free(lineptr);
		return(NULL);
	}

	if ((getline(&lineptr, &n, stdin)) < 0) /** Error handling for getline() failure */
	{
		printf("Could not read line");
		free(lineptr);
		return (NULL);
	}
	
	printf("%s\n", lineptr);
	return (lineptr);
}

char **parse_line(char *line)
{
	int n = strlen(line);

	char **tokens = malloc(n * sizeof(char));

	char *token;

	int pos = 0;

	if (!tokens)
	{
		printf("Allocation Error.");
		return (NULL);
	}
	
	token = strtok(line, TOKEN_DELIMETERS);

	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, TOKEN_DELIMETERS);
	}
	tokens[pos] = NULL;

	return(tokens);
}
