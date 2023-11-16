#include "shell.h"

/**
 * handler - handles signal
 * @num: signal num
 *
 */
void handler(int num)
{
	char *prompt = "Welcome to our shell ~$$ ";
	size_t len;

	(void)num;
	len = _strlen(prompt);
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, prompt, len);
}
