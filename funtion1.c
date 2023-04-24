#include "main.h"

void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *temp;

	/* Read one line */
	for( ;; )
	{
		int c = fgetc(stdin);

		line[count++] = (char) c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	temp = strtok(line, " \n");

	/* parse the line into words */
	while ( temp != NULL )
	{
		array[i++] = strdup (temp);
		temp = strtok (NULL, " \n");
	}

	/* first word = command */
	strcpy (cmd, array[0]);

	/* parameters */
	for (int j = 0; j < i; j++)
	{
		par[j] = array[j];
	}
	par[j] = NULL; /* NULL terminate the parameters */
}
