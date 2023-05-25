#include "shell.h"

/**
 * parse_command - Parses command recieved from input
 * @S_INPUT: String collected from input
 *
 * Return: argums_ Parsed strings to be used as arguments
 */
char **parse_command(char *S_INPUT)
{
int j, size_buff = SIZEBUF;
char **argums, *argum;


if (S_INPUT[0] == ' ' && S_INPUT[F_strlen(S_INPUT)] == ' ')
{
exit(0);
}
if (S_INPUT == NULL)
{
return (NULL);
}
argums = malloc(sizeof(char *) * size_buff);
if (!argums)
{
free(argums);
perror("hsh");
return (NULL);
}
argum = F_strtok(S_INPUT, "\n\t\r\a ");
for (j = 0; argum; j++)
{
argums[j] = argum;
argum = F_strtok(NULL, "\n\t\r\a ");
}
argums[j] = NULL;

return (argums);
}
