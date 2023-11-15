#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: string length
 */

int _strlen(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: Always 0
 */

int _strcmp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}


/**
 * _strdup - duplicates a string
 * @str: string
 * Return: Always 0
 */

char *_strdup(char *str)
{
	int len;
	char *i;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	i = malloc(sizeof(char) * (len + 1));
	if (i == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
	{
		i[len] = str[len];
	}
	i[len] = '\0';
	return (i);
}

/**
 * _strcount - counts number of words in a string
 * @str: string
 * Return: word count
 */

int _strcount(char *str)
{
	int i;
	int j = 1;
	int count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && j == 1)
		{
			count += 1;
			j = 0;
		}
		if (str[i + 1] == ' ')
			j = 1;
	}
	return (count);
}

/**
 * _strcat - concatenates two strings
 * @dest: string 1
 * @src: string 2
 * Return: new string
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
