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
	printf("Tokenizer start...");
	int token_count = 0;
	char **tokens = malloc(MAX_TOKENS * sizeof(char));
	char *tok = strtok(line, delim);

	while (tok != NULL)
	{
		tokens[token_count] = strdup(tok);
		token_count++;
		tok = strtok(NULL, delim);
	}

	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * free_tokens - frees memory from tokens
 * @tokens: tokens to free
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
