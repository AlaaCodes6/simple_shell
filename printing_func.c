#include "shell.h"

/**
 * _puts - prints a string
 * @str: string
 * Return: nothing
 */

void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: character
 * Return: 1 on Success.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
