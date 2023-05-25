#include "shell.h"
/**
 * command_path -  Search for executable command in the path
 * @cmd: command parzed
 * Return: 0 on success or 1 on failure
 */
int command_path(char **cmd)
{
char *path, *value, *cmd_path;
struct stat Buffer;
path = F_getenv("PATH");
value = F_strtok(path, ":");
while (value != NULL)
{
cmd_path = build(*cmd, value);
if (stat(cmd_path, &Buffer) == 0)
{
*cmd = F_strdup(cmd_path);
free(cmd_path);
free(path);
return (0);
}
free(cmd_path);
value = F_strtok(NULL, ":");
}
free(path);
free(value);
return (1);
}
/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *token, char *value)
{
char *cmd;
size_t len;
len = F_strlen(value) + F_strlen(token) + 2;
cmd = malloc(sizeof(char) * len);
if (cmd == NULL)
{
free(cmd);
return (NULL);
}
memset(cmd, 0, len);
cmd = F_strcat(cmd, value);
cmd = F_strcat(cmd, "/");
cmd = F_strcat(cmd, token);
return (cmd);
}
/**
 * F_getenv - retrieve the value of an environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *F_getenv(char *name)
{
int k, i, j;
size_t name_len, value_len;
char *value;
name_len = F_strlen(name);
for (i = 0 ; environ[i]; i++)
{
if (F_strncmp(name, environ[i], name_len) == 0)
{
value_len = F_strlen(environ[i]) - name_len;
value = malloc(sizeof(char) * value_len);
if (!value)
{
free(value);
perror("unable to alloc");
return (NULL);
}
j = 0;
for (k = name_len + 1; environ[i][k]; k++, j++)
{
value[j] = environ[i][k];
}
value[j] = '\0';
return (value);
}
}
return (NULL);
}
