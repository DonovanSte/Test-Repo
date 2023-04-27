#include "main.h"

/**
 * process_pid - PID & PPID
 *
 * Return: Always 0.
 */
int process_pid(void)
{
	pid_t my_pid;
	pid_t parent_pid;

	my_pid = getpid();
	parent_pid = getppid();

	printf("%u\n", parent_pid);
	printf("%u\n", my_pid);
	return (0);
}
