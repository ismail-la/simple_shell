#include "shell.h"
/**
 * Function_separator - This function separates input by semi-colon ;
 * or ampersand and returns an array of commands.
 * @Stdin_Input: String gathered from stdin
 * Return: array Parsed strings
 */
char **Function_separator(char *Stdin_Input)
{
int i, buffsize = SIZEBUF;
char *cmd, **cmds;

if (Stdin_Input[0] == ' ' && Stdin_Input[F_strlen(Stdin_Input)] == ' ')
{
exit(0);
}
if (Stdin_Input == NULL)
{
return (NULL);
}
cmds = malloc(sizeof(char *) * buffsize);
if (!cmds)
{
free(cmds);
perror("hsh");
return (NULL);
}
cmd = F_strtok(Stdin_Input, ";&");
for (i = 0; cmd; i++)
{
cmds[i] = cmd;
cmd = F_strtok(NULL, ";&");
}
cmds[i] = NULL;
return (cmds);
}
