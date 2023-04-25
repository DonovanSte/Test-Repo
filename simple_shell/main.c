#include "main.h"

extern char **environ;

int main(int ac, char **argv)
{
    char *promt = "(myShell) $ ";
    char *lineptr = NULL;
    char *lineptr_cpy = NULL;
    const char *delim = " \n";
    size_t n = 0;
    ssize_t nread;
    int token_num = 0;
    char *token;
    int i;

    (void)ac;

    while (1)
    {
        printf("%s", promt);
        nread = getline(&lineptr, &n, stdin);

        if (nread == -1)
        {
            return (-1);
        }
        else if (nread == 1)
        {
            continue;
        }
        else if (nread > 4096)
        {
            printf("Error: Input line too long.\n");
            continue;
        }
        if (strcmp(lineptr, "exit\n") == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(lineptr, "env\n") == 0)
        {
            char **env = environ;
            while (*env)
            {
                printf("%s\n", *env++);
            }
            continue;
        }

        lineptr_cpy = malloc(sizeof(char) * nread);
        if (lineptr_cpy == NULL)
        {
            perror("memory allocation error");
            return (-1);
        }    

        strcpy(lineptr_cpy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            token_num++;
            token = strtok(NULL, delim);
        }
        token_num++;

        argv = malloc(sizeof(char *) * token_num);

        token = strtok(lineptr_cpy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        execmd(argv);
    }

    free(lineptr_cpy);
    free(lineptr);

    return (0);
}
