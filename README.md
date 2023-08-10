# Holberton C21 //simple_shell

A Unix shell is a program that allows users to interact with a Unix-like operating system through a command line interface. It serves as both a command language for executing commands and a scripting language for creating shell scripts that control the system's execution.

### Usage

1.  Run the program.
2.  Enter commands at the prompt.
3.  Commands are executed in separate processes.
4.  Parent process waits for child processes by default.
5.  Background execution can be achieved using wait() or waitpid().


### Functionality

The user is prompted using **$** to indicate the program has started.

**simple_shell.c** begins the loop of waiting for user input. It uses the *getline* function to read the input.

**tokenizer** gets passed the input from the **main** function in simple_shell.c, and tokenizes the input into a dynamically allocated array of strings. 

The input is passed to **exec_cmd** to determine if the function is built in or not. 

**launch_process** is passed the command if it is not built-in. This function will fork() so the child process can execute the command instead of the parent. The parent then waits.

**pathfinder** allows the child process to find the environment to execute the command passed to it. It will call the **tokenizer** function to properly execute the command after obtaining the path. 

**free_args** is a custom command that allows for the arguments passed along the function to be freed through iteration.  

### Header Files
The following files in the C standard library were utilized:
*string.h*
*stdio.h*
*stdlib.h*
*errno.h*
*sys/wait.h*
*sys/types.h*
*unistd.h*

### Built-Ins
Some commands are built-in functions that do not require the use of the `fork()` system call. These functions are directly executed within the shell's context, without creating separate processes. The ones utilized in this project are **cd** and **exit**.


### Flowchart: How did we get here?
+---------------------+
|     Start Program   |
+----------+----------+
           |
           |
           v
+----------+----------+
|   Initialize Shell  |
+----------+----------+
           |
           |
           v
+----------+----------+
|    Process Built-   |
|     in Commands     |
+----------+----------+
           |
           |
           v
+----------+----------+
|    Execute Built-   |
|     in Command      |
+----------+----------+
           |
           |
           v
+----------+----------+
|    Terminate        |
|     Program         |
+----------+----------+
           |
           |
           v
+----------+----------+
|   Launch Process    |
+----------+----------+
           |
           |
           v
+----------+----------+
|    Wait for Child   |
|     Process         |
+----------+----------+
           |
           |
           v
+----------+----------+
|     Continue        |
|    Processing       |
+----------+----------+
           |
           |
           v
+----------+----------+
|    End Program      |
+---------------------+

## Compilation

**simple_shell** was compiled using *gcc*

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh




