#include <stdio.h>
#include <stdlib.h>
/**
 * read_input - reads user input and stores it into string
 * Return: dynamically allocated string
 */
char *read_input()
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t num_chars;

	num_chars = getline(&input, &input_size, stdin);

	if (num_chars == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if (num_chars > 0 && input[num_chars - 1] == '\n')
		input[num_chars - 1] = '\0';

	return (input);
}
