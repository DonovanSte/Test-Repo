#include "main.h"

/**
 * print_prompt - prints the prompt
 * @prompt: prompt to be printed
 */
void print_prompt(char *prompt)
{
	printf("%s", prompt);
}

/**
 * read_line - reads a line of input from stdin
 * @n: size of input buffer
 *
 * Return: pointer to input buffer
 */
char *read_line(size_t *n)
{
	ssize_t nread;
	char *lineptr = NULL;

	nread = getline(&lineptr, n, stdin);

	if (nread == -1)
	{
		return (NULL);
	}

	return (lineptr);
}

/**
 * execute_command - executes the given command
 * @argv: argument vector
 *
 * Return: 0 on success, 1 otherwise
 */
int execute_command(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		system("clear");
		exit(EXIT_SUCCESS);
	}
	if (strcmp(argv[0], "clear") == 0)
	{
		system("clear");
		return (0);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
			printf("%s\n", *env++);
		return (1);
	}
	else
	{
		execmd(argv);
		return (1);
	}
}

/**
 * tokenize_line - tokenizes a line of input
 * @lineptr: input buffer
 * @argv: pointer to argument vector
 *
 * Return: number of tokens
 */
int tokenize_line(char *lineptr, char ***argv)
{
	char *lineptr_cpy = NULL;
	const char *delim = " \n";
	int token_num = 0;
	char *token;
	int i;

	lineptr_cpy = malloc(sizeof(char) * strlen(lineptr));
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
	return (token_num);
}
