#include "shell.h"

/**
 * _myenv - prints the cuurent environment
 *
 * Return: Always 0
 */

int _myenv(void)
	{
		int i;

		for (i = 0; environ[i]; i++)
			_puts(environ[i]);
		return (0);
}


/**
 * _getenv - gets the value of an environ variable
 * @name: env name
 *
 * Return: value of environ
 */

char *_getenv(const char *name)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		j = _PATHstrcmp(name, environ[i]);
		if (j == 0)
			return (environ[i]);
	}
	return (NULL);
}
