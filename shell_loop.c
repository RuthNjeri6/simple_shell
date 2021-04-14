#include "headers.h"

/**
* shell_loop - display prompt and wait for user to type in a command
* @void: none
*
* Return: void
*/
void shell_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("#cisfun$ ");
        line = read_line();
        args = split_line(line);
        status = command_picker(args);

        free(line);
    } while (status);
}
