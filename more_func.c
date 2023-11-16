#include "shell.h"

/**
 * get_input - reads input
 *
 * Return: buffer
 */

char *get_input(void)
{
	ssize_t input_r = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	input_r = getline(&buffer, &n, stdin);
	if (input_r == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[input_r - 1] == '\n' || buffer[input_r - 1] == '\t')
		buffer[input_r - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}

/**
 * path_buffer - gets a string to execute
 * @av: user of strings
 * @PATH: path string
 * @dup: copy of PATH string
 * Return: Always 0
 */

char *path_buffer(char **av, char *PATH, char *dup)
{
	char *tok, *newstr = NULL, *fullpathbuff = NULL;
	static char tmp[256];
	int tok_length = 0, PATHcount = 0, fullpathflag = 0, j = 0;
	struct stat h;

	dup = NULL;
	dup = _strdup(PATH);
	PATHcount = _splitpath(dup);
	tok = strtok(dup, ": =");
	while (tok != NULL)
	{
		newstr = _chain(tmp, av, tok);
		if (stat(newstr, &h) == 0)
		{
			fullpathbuff = newstr;
			fullpathflag = 1;
			break;
		}
		if (j < PATHcount - 2)
		{
			tok_length = _strlen(tok);
			if (tok[tok_length + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					fullpathbuff = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		j++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuff = av[0];
	free(dup);
	return (fullpathbuff);
}

/**
 * check_builtin - check for built-in
 * @av: user of strings
 * @buffer: buffer
 * @exitstatus: exit status
 * Return: 1 if user string = env or 0 if not.
 */

int check_builtin(char **av, char *buffer, int exitstatus)
{
	int a;

	if (_strcmp(av[0], "env") == 0)
	{
		_myenv();
		for (a = 0; av[a]; a++)
			free(av[a]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (a = 0; av[a]; a++)
			free(av[a]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
