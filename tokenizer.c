#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * tokenizer - tokenizes a string into an array of tokens
 * @line: string to tokenize
 * @delim: delimeter
 * Return: array of tokens
 */
char **tokenizer(char *line, char *delim)
{
	int max = 10;
	int i = 0;
	int n;
	char **tokens;
	char *token, *linecp;

	linecp = strdup(line);

	tokens = malloc(max * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc error");
		return (NULL);
	}
	token = strtok(linecp, delim);

	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("strdup");
			for (n = 0; n < i; n++)
			{
				free(tokens[n]);
			}
			free(tokens);
			free(linecp);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	free(linecp);
	return (tokens);
}
