#include "shell.h"
/**
 * F_history - write file with user inputs
 * @input: user input
 * Return: 0 on success -1 if failed
 */
int F_history(char *input)
{
char *filename = "history_record";
ssize_t fd, w;
int len = 0;
if (!filename)
{
return (-1);
}
fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
if (fd < 0)
{
return (-1);
}
if (input)
{
while (input[len])
{
len++;
}
w = write(fd, input, len);
if (w < 0)
{
return (-1);
}
}
return (1);
}
