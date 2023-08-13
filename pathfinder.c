#include "shell.h"

/**
 * pathfinder - Resolves the path for a command
 * @cmdtoks: The command and its arguments
 * Description: resolved path is stored in the cmdtoks[0] string.
 */
void pathfinder(char **cmdtoks)
{
    char *path = getenv("PATH");
    char *dir;
    char *command;
    char *path_copy = strdup(path);

    if (path_copy == NULL)
    {
        perror("strdup");
        return;
    }

    size_t path_len = strlen(path_copy);
    if (path_len > 0 && path_copy[path_len - 1] == '\n')
	    path_copy[path_len - 1] = '\0';

    command = cmdtoks[0];

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        char *path_command = malloc(strlen(dir) + strlen(command) + 2);
        if (path_command == NULL)
        {
            perror("malloc");
            free(path_copy);
            return;
        }

        sprintf(path_command, "%s/%s", dir, command);

        if (access(path_command, X_OK) == 0)
        {
            free(cmdtoks[0]);
            cmdtoks[0] = path_command;
            free(path_copy);
            return;
        }

        free(path_command);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
}
