#include "shell.h"

/**
 * main - Entry Point
 *
 * Return: 0 on Success
 */

int main(void)
{
	int exitstatus = 0;
	char *PATH = NULL, *fullpathbuff = NULL, *dup = NULL, *buffer = NULL;
	char **av;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		prompt();
		buffer = get_input();
		if (*buffer != '\0')
		{
			av = splitter(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			fullpathbuff = path_buffer(av, PATH, dup);
			if (check_builtin(av, buffer, exitstatus) == 1)
				continue;
			exitstatus = execute(av, buffer, fullpathbuff);
			}
			else
				free(buffer);
		}
		return (0);
}
