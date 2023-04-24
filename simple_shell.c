#include "main.h"

void type_prompt()
{
	static int first_time = 1;

	if (first_time) /* Clear screen for first time */
	{
		const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";

		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI,12);
		first_time = 0;
	}

	printf("#"); /* display promt */
}

int main()
{
	char cmd[100], command[100], *parameters[20];
	
	/* environment variable */
	char *envp[] = { (char *) "PATH=/bin", 0};

	while (1) /* Endless loop */
	{
		type_prompt(); /* Display prompt on screen */
		read_command(command, parameters); /* read input from terminal */
		if ( fork() != 0 )
			wait( NULL );
		else
		{
			strcpy (cmd, "/bin/");
			strcat (cmd, command);
			execve (cmd, parameters, envp); /* Executes the command */
		}
		if (strcmp ( command, "exit") == 0)
			break;
		if (strcmp ( command, "clear") == 0)
			system("clear");
	}

	return (0);
}
