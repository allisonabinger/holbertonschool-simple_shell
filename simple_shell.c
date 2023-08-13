#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Description: This function serves as the entry point of the shell program.
 * It reads user input, tokenizes the input into commands and arguments,
 * and executes the commands accordingly.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t chars_read = 0;
    char **cmdtoks;
    int bicmd;

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

        if (cmdtoks != NULL)
        {
            bicmd = exec_cmd(cmdtoks);

            if (bicmd != 0)
            {
                pathfinder(cmdtoks);

                if (cmdtoks[0] != NULL)
                {
                    launch_process(cmdtoks);
                }
                else
                {
                    fprintf(stderr, "Command not found: %s\n", cmdtoks[0]);
                }
            }
            free_args(cmdtoks);
        }
        free(line);
    }
    return (0);
}
