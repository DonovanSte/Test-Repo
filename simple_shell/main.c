#include "main.h"


int main(int ac, char **argv)
{
	char *prompt = "(myShell) $ ";
	char *lineptr = NULL;
	size_t n = 0;
	int token_num, i;
	int ret;

	(void)ac;

	while (1)
	{
		print_prompt(prompt);
		lineptr = read_line(&n);

		if (lineptr == NULL)
		{
			return (-1);
		}
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

		ret = tokenize_line(lineptr, &argv);
		if (ret == -1)
		{
			free(lineptr);
			continue;
		}

		token_num = ret;

		ret = execute_command(argv);
		if (ret == -1) {
			free(lineptr);
			for (i = 0; i < token_num; i++)
			{
				free(argv[i]);
			}
			free(argv);
			continue;
		}

		free(lineptr);
		for (i = 0; i < token_num; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}

	return (0);
}
