#include "shell.h"

/**
 * prompt - prints a prompt
 *
 * Return: Always 0
 */

int prompt(void)
{
	char *prompt = "$ ";
	ssize_t output = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		output = write(STDOUT_FILENO, prompt, 2);
		if (output == -1)
			exit(0);
	}
	return (0);
}
