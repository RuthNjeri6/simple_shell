#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int command_executer(char *pathname, char *argv[]);
char *read_line(void);
void shell_loop(void);
char **split_line(char *line);
int command_picker(char **args);
int shell_exit(void);
int _strcmp(char *name, char *str);
int shell_env(void);

#endif /* _HEADERS_H_ */
