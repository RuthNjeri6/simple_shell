#include "headers.h"

/**
* shell_env - prints current environment
* @void: none
*
* Return: integer
*/
int shell_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
