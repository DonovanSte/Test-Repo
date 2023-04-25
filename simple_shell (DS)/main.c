#include "main.h"

/**
 * main - Entry point for the shell program
 * @ac: The number of command line arguments
 * @argv: An array of pointers to the command line arguments
 *
 * This function initializes the shell prompt, calls process_input() to handle
 * user input, and returns 0 on success.
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *prompt = "(myShell) $ ";
	(void)ac;
	(void)argv;
	process_input(prompt);
	return (0);
}
