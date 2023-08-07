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
	int bufsize = 64;
	int pos = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;
	
	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		return (NULL);
	}
	
	token = strtok(line, delimiters);
	while (token != NULL)
	{
 tokens[position] = strdup(token); // Make a copy of the token
 position++;

 if (position >= bufsize) {
 bufsize += 64;
 tokens = realloc(tokens, bufsize * sizeof(char*));
 if (!tokens) {
 fprintf(stderr, "Allocation error\n");
 exit(EXIT_FAILURE);
 }
 }

 token = strtok(NULL, delimiters);
 }
 tokens[position] = NULL;
 return tokens;
}
