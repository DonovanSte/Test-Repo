#include "main.h"

extern char **environ;

void print_prompt(char *prompt)
{
	printf("%s", prompt);
}

char* read_line(size_t *n)
{
	ssize_t nread;
	char *lineptr = NULL;

	nread = getline(&lineptr, n, stdin);

	if (nread == -1)
	{
		return NULL;
	}

	return lineptr;
}

int execute_command(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		char **env = environ;
		while (*env)
		{
			printf("%s\n", *env++);
		}
		return 1;
	}
	else
	{
		execmd(argv);
		return 1;
	}
}

int tokenize_line(char *lineptr, char ***argv)
{
	char *lineptr_cpy = NULL;
	const char *delim = " \n";
	int token_num = 0;
	char *token;
	int i;

	lineptr_cpy = malloc(sizeof(char) * strlen(lineptr));
	if (lineptr_cpy == NULL) {
		perror("memory allocation error");
		return -1;
	}

	strcpy(lineptr_cpy, lineptr);

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		token_num++;
		token = strtok(NULL, delim);
	}
	token_num++;

	*argv = malloc(sizeof(char *) * token_num);

	token = strtok(lineptr_cpy, delim);

	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * strlen(token));
		strcpy((*argv)[i], token);

		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;

	free(lineptr_cpy);

	return token_num;
}