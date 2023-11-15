#include "shell.h"


/**
 * _splitpath - split path into its components
 * @str: string
 *
 * Return: number of path components
 */

int _splitpath(char *str)
{
	int i;
	int j = 1;
	int n = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && j == 1)
		{
			n += 1;
			j = 0;
		}
		if (str[i + 1] == ':')
			j = 1;
		}
	return (n);
}

/**
 * splitter - splits a string into tokens
 * @buffer: string
 *
 * Return: av
 */

char **splitter(char *buffer)
	{
		char *token;
		int i = 0, n = 0;
		char *delimiter = " \n";
		char **av;

		n = _strcount(buffer);
		if (!n)
			return (NULL);

		av = malloc((n + 1) * sizeof(char *));
		if (av == NULL)
			exit(1);

		token = strtok(buffer, delimiter);
		while (token != NULL)
		{
			av[i] = _strdup(token);
			token = strtok(NULL, delimiter);
			i++;
		}
		av[i] = NULL;
		return (av);
}


/**
 * _cmpPATHenv - compares PATH with environ
 * @s1: PATH string
 * @s2: environ string
 * Return: Always 0
 */

int _cmpPATHenv(const char *s1, const char *s2)
	{
		int a;

		for (a = 0; s2[a] != '='; a++)
		{
			if (s1[a] != s2[a])
			return (-1);
		}
		return (0);
}
