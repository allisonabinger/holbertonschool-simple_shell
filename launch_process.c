#include "shell.h"

/**
 * launch_process - Launches a process using fork and execve
 * @cmdtoks: The command and its arguments
 *
 * Description: This function launches a new process using the fork and execve
 * system calls. The command and its arguments are passed as cmdtoks.
 */
void launch_process(char **cmdtoks)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }
    else if (pid == 0)
    {
        if (execve(cmdtoks[0], cmdtoks, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do
        {
            if (waitpid(pid, &status, WUNTRACED) == -1)
            {
                perror("waitpid");
                return;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
