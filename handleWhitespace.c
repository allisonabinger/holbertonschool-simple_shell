#include "shell.h"
/**
 * handleWhitespace - controls whitespace in user input
 * @line: user input
 * @line_length
 * Return: # of whitespace characters in line
*/
int handleWhitespace(char *line, ssize_t line_length)
{
    ssize_t wslength = strlen(TOKEN_DELIMETERS);
    ssize_t i, j, k;

    for (i = 0; i < line_length; i++)
    {
        for (j = 0; j < wslength; j++)
        {
            if (line[i] == TOKEN_DELIMETERS[j])
            { 
                k++;
            }
        }
    }
    return(k);
}