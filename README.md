# SShell
Welcome to SShell, a simple shell (terminal) implemented in C that works on UNIX-like operating systems. This shell supports basic command execution, allows changing the username, and provides basic information about itself.

## Features
Execute UNIX commands like ls, cat, pwd, etc.
Customize the username prompt (stored in a file).
Provides basic shell information for users.
## How It Works
Command Execution: The shell reads user input, parses it into commands and arguments, and then uses fork() and execvp() to execute commands.
Username Management: The shell reads the username from a file (user.txt). If this file doesn't exist, a default username is used. Users can change the username during the session by typing chguser.
Shell Info: Typing SShell as a command will print information about this shell, including how to run it on Windows using WSL (Windows Subsystem for Linux).
## How to Use
Clone the repository:

```
git clone https://github.com/your-username/SShell.git
```
Compile the code:

Navigate to the directory and compile using gcc:

```
gcc -o sshell sshell.c
```
Run the shell:
```
./sshell
```
## Change username:

Type chguser to change the current username in the prompt.

## SShell Information:

Type SShell to know more about this shell and its features.

## File Structure
sshell.c: The main source code file containing the implementation of the shell.
user.txt: A file where the username is stored and used in the shell prompt.
## Requirements
A UNIX-like operating system (Linux, macOS, etc.)
GCC (GNU Compiler Collection)
## Known Issues
This shell works on UNIX-like systems. On Windows, you can install WSL (Windows Subsystem for Linux) to run the shell.
Limited command parsing (handles basic commands but lacks advanced features like piping or redirection).
## Future Improvements
Add support for piping (|) and redirection (>, <).
Improve error handling for invalid commands.
Extend the shell to support scripting.
## Contributing
If you'd like to contribute to SShell, feel free to fork the repository, create a new branch, and submit a pull request.
