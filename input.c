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
	size_t n = 0; /** max size of acceptable inputs */
	ssize_t chars_read;

	chars_read = getline(&lineptr, &n, stdin);

	if (chars_read < 0) /** Error handling for getline() */
	{
		printf("Could not read line");
		free(lineptr);
		return (NULL);
	}

	printf("%s\n", lineptr);
	return (lineptr);
}

/**
 * parse_line- parses through input and returns array of tokens
 * @line: input from main user
 * Return: array of tokens.
 */
char **parse_line(char *line)
{
	int bufsize = 64;
	int pos = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	printf("parse_line start...");

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		return (NULL);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[pos] = strdup(token);
		pos++;
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[pos] = NULL;

	printf("%s\n", tokens[pos]);
	return (tokens);
}
