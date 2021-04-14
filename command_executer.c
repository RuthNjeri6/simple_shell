#include "headers.h"

/**
* command_executer - executes the command typed by the user
* @pathname: first parameter
* @argv: second parameter
*
* Return: pointer
*/
int command_executer(char *pathname, char *argv[])
{
	pid_t pid;
	int status, idx = 0, flag = 0;
	char path[1024] = "/bin/";

	while (strlen(pathname) > 0 && path[idx] != '\0')
	{
		if (pathname[idx] == path[idx])
		{
			flag++;
		}
		idx++;
	}
	pid = fork();
	if (pid == 0)
	{
		if (flag == 5)
		{
			if (execve(pathname, argv, NULL) == -1)
			{
				printf("No such file\n");
				exit(3);
			}
		}
		if (execve(strcat(path, pathname), argv, NULL) == -1)
		{
			printf("No such file\n");
			exit(3);
		}
	}
	else if (pid < 0)
	{
		printf("Error forking\n");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
