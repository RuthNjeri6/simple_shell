#include "headers.h"
/**
* command_picker - checks for builltin commands
* @args: array of strings
*
* Return: int
*/
int command_picker(char **args)
{

char *builtin_cmd[] = {
"exit",
"env"
};

if (args[0] == NULL)
{
return (1);
}
if (strcmp(args[0], builtin_cmd[0]) == 0)
{
return (shell_exit());
}
if (strcmp(args[0], builtin_cmd[1]) == 0)
{
return (shell_env());
}
return (command_executer(args[0], args));
}
