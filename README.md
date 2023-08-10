# Shell

## About
Shell is a command-line interpreter or shell for Unix-like operating systems. It provides a command line user interface and serves as both an interactive command language and a scripting language. The shell is used by the operating system to control the execution of the system using shell scripts.

## Usage
To use the shell, simply compile and run the program. The main function `main()` starts the shell and enters the main loop. It handles the execution of both built-in commands and non-built-in commands by calling the appropriate functions.

The `exec_cmd()` function executes built-in commands directly or passes non-built-in commands to the `launch_process()` function. The `launch_process()` function is responsible for executing non-built-in commands by creating and managing child processes.

## Dependencies
This shell program depends on the following standard C libraries:
- string.h
- stdio.h
- stdlib.h

## Building
To build the shell program, you can use the following command:
[./shell]
 
## Contributing
Contributions to this shell program are welcome! If you encounter any issues, please open an issue on the GitHub repository. Feel free to submit pull requests with any improvements or bug fixes. 
