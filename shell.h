#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* String Functions */

char *_strdup(char *str);
int _strcount(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

/*Printing Functions*/

void _puts(char *str);
int _putchar(char c);

/*Memory Functions*/

char *_memset(char *s, char b, unsigned int n);

/* More Functions */

int prompt(void);
char *get_input(void);
char *path_buffer(char **av, char *PATH, char *dup);
int check_builtin(char **av, char *buffer, int exitstatus);
int execute(char **av, char *buffer, char *fullpathbuff);
char **splitter(char *buffer);
int _splitpath(char *str);
int _cmpPATHenv(const char *s1, const char *s2);
char *_chain(char *tmp, char **av, char *tok);
char *_getenv(const char *name);
int _myenv(void);



#endif
