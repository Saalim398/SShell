#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

void parse_input(char *input, char **args) {
    char *token = strtok(input, " \n");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; 
}

int main()
{
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    printf("Welcome to SShell...");
    printf("\nVersion 1.0.1");
    printf("\nType SShell to know about its features and commands\n");

    char username[50];
    FILE *fptr;


    fptr = fopen("user.txt", "r");
    if (fptr != NULL) {
        fgets(username, 50, fptr);
        fclose(fptr);
    } else {
        strcpy(username, "default"); 
    }

    while (1)
    {
        printf("SShell@%s$> ", username);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        if (strcmp(input, "SShell\n") == 0)
        {
            printf("\nThis SShell works only on UNIX-like operating systems. To use it on Windows, you can install a Linux distribution like Ubuntu or Debian on WSL.");
            printf("\nTo change the username, type 'chguser'.\n");
        }
        else if (strcmp(input, "chguser") == 0)
        {
            fptr = fopen("user.txt", "w");
            if (fptr != NULL) {
                printf("Enter new username: ");
                scanf("%s", username);
                fprintf(fptr, "%s", username);
                fclose(fptr);
            }
        }
        else
        {
            parse_input(input, args);
            pid_t pid = fork();
            if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                    perror("Error executing command");
                }
            } else if (pid < 0) {
                perror("Fork failed");
            } else {
                wait(NULL);
            }
        }
    }
    
    return 0;
}
