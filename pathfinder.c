#include "shell.h"

/**
 * pathfinder - Resolves the path for a command
 * @cmdtoks: The command and its arguments
 * Description: resolved path is stored in the cmdtoks[0] string.
 */
void pathfinder(char **cmdtoks)
{
    char *command = cmdtoks[0];
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir;

    if (path_copy == NULL)
    {
        perror("strdup");
        return;
    }

    dir = strtok(path_copy, ":");

    while (dir != NULL)
    {
        size_t dir_len = strlen(dir);
        size_t cmd_len = strlen(command);
        char *path_command = malloc(dir_len + cmd_len + 2);

        if (path_command == NULL)
        {
            perror("malloc");
            free(path_copy);
            return;
        }

        snprintf(path_command, dir_len + cmd_len + 2, "%s/%s", dir, command);

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