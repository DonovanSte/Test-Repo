#include "main.h"

/**
 * process_input - Process input commands from user
 * @prompt: Prompt to display before user input
 *
 * This function repeatedly prompts the
 * user for input, reads each line of input
 * using read_line(), and processes each command using process_command().
 */
void process_input(char *prompt)
{
	char *lineptr = NULL;
	size_t n = 0;

	while (1)
	{
		print_prompt(prompt);
		lineptr = read_line(&n);

		if (lineptr == NULL)
			return;
		else if (strcmp(lineptr, "\n") == 0)
		{
			free(lineptr);
			continue;
		}
		else if (strlen(lineptr) > 4096)
		{
			printf("Error: Input line too long.\n");
			free(lineptr);
			continue;
		}
		process_command(lineptr);
		free(lineptr);
	}
}

/**
 * process_command - Process a single command
 * @lineptr: Pointer to the input command string
 *
 * This function tokenizes the input command using tokenize_line(),
 * executes the command using execute_command(), and frees memory.
 */
void process_command(char *lineptr)
{
	char **argv = NULL;
	int token_num, i;
	int ret;

	ret = tokenize_line(lineptr, &argv);

	if (ret == -1)
		return;
	token_num = ret;
	ret = execute_command(argv);

	if (ret == -1)
	{
		for (i = 0; i < token_num; i++)
			free(argv[i]);
		free(argv);
		return;
	}
	for (i = 0; i < token_num; i++)
		free(argv[i]);
	free(argv);
}
