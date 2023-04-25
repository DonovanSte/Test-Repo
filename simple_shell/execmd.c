#include "main.h"

void execmd(char **argv)
{
    char *command = NULL, *actual_command = NULL;
    pid_t pid;
    int status;

    if (argv)
    {
        command = argv[0];
        actual_command = get_location(command);

        if (actual_command == NULL)
        {
            printf("Command not found: %s\n", command);
            return;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            if (execve(actual_command, argv, NULL) == -1)
            {
                perror("Error:");
            }
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
        }
    }
}