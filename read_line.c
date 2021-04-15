#include "headers.h"
/**
* read_line - reads commands as one string
* @void: none
*
* Return: pointer
*/
char *read_line(void)
{
char *ptr;
int ch;
int pos = 0;
pos = 0;
ptr = malloc(sizeof(char) * 1024);

if (ptr == NULL)
{
printf("Failed to allocate memory\n");
exit(99);
}
while (1)
{
ch = getchar();
if (ch == '\n' || ch == '\0')
{
ptr[pos] = '\0';
return (ptr);
}
ptr[pos] = ch;
pos++;
}

}
