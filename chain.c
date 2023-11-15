#include "shell.h"

/**
 * _chain - chains path with user strings
 * @tmp: static array to store concatenated string
 * @av: array of user strings
 * @tok: token of path
 * Return: concatenated string
 */

char *_chain(char *tmp, char **av, char *tok)
{
	int i = 0;

	_memset(tmp, 0, 256);
	i = _strlen(tok) + _strlen(av[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[i - 1] = '\0';
	return (tmp);
}
