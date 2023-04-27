#include "main.h"

int prompt(int ac, char **av)
{
	while(1)
	{
		char buffer[1024];
		int i = 0;
		char c;

		printf("$ ");
		fflush(stdout);

		while ((c = getchar()) != '\n' && c != EOF)
		{
			buffer[i] = c;
			i++;
		}

		buffer[i] = '\0';
		printf("%s\n", buffer);
		continue;
	}
	return 0;
}
