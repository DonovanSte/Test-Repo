#include "main.h"

int main(int argc, char **argv)
{
	int i;
	pid_t pid;
	int status;

	while (1)
	{
		char *line;
		char *args[256];
		int nargs = 0;

		printf("$ ");
		fflush(stdout);

		/* read a line of input */
		line = read_line();

		if (!line)
		{
			/* end of file or error */
			break;
		}

		/* split the line into arguments */
		for (char *p = line; *p; )
		{
			while (*p == ' ' || *p == '\t')
			{
				*p++ = '\0';
			}
			if (*p)
			{
				args[nargs++] = p;
			}
			while (*p && *p != ' ' && *p != '\t')
			{
				p++;
			}
		}
		args[nargs] = NULL;

		/* create a child process to execute the command */
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			/* child process */
			execvp(args[0], args);
			perror("execvp");
			exit(1);
		}
		else
		{
			/* parent process */
			waitpid(pid, &status, 0);
		}
		free(line);
	}
	return 0;
}
