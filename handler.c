#include "shell.h"

/**
 * handler - handles signal
 * @num: signal num
 *
 */
void handler(int num)
{
	char *prompt = "Welcome to our shell ~$$ ";
	(void)num;

	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, prompt, _strlen(prompt));
}
