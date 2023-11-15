#include "shell.h"

/**
 * exit_shell - function to exit the shell
 * Return:
 */

void exit_shell(void)
{
	const char *exitmessage = "Exiting shell..\n";

	write(STDOUT_FILENO, exitmessage, _strlen(exitmessage));

	exit(0);
}
