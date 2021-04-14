#include "headers.h"

/**
* split_line - splits the line read to commands
* @line: points to char
*
* Return: on success array of strings, otherwise exit
*/
char **split_line(char *line)
{
char **tokens;
char *token;
int position = 0;
int buffsize = 1024;

tokens = malloc(sizeof(char *) * buffsize);

if (tokens == NULL)
{
perror("Malloc failure\n");
exit(98);
}

token = strtok(line, " ");
while (token != NULL)
{
tokens[position] = token;
position++;
token = strtok(NULL, " ");
}
tokens[position] = NULL;
return (tokens);
}
