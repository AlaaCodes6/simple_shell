#include "shell.h"

/**
 * execute - creates child process
 * @av: user of strings
 * @buffer: buffer
 * @fullpathbuff: user input
 * Return: Always 0
 */

int execute(char **av, char *buffer, char *fullpathbuff)
	{
		int a, i, status, exitstatus = 0;
		pid_t child_pid;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("An error has occured");
			exit(1);
		}
		if (child_pid == 0)
		{
			i = execve(fullpathbuff, av, environ);
			if (i == -1)
			{
				perror(av[0]);
				for (a = 0; av[a]; a++)
					free(av[a]);
				free(av);
				free(buffer);
				exit(127);
			}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			exitstatus = WEXITSTATUS(status);
		}
		for (a = 0; av[a]; a++)
			free(av[a]);
		free(av);
		free(buffer);
		return (exitstatus);
}
