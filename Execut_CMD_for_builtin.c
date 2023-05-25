#include "shell.h"

/**
 * Dir_change - Changes directory
 * @cmd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int Dir_change(char **cmd, __attribute__((unused))int st)
{
int VAL = -1;
char _CWD[PATH_MAX];

/*****loop******/
if (cmd[1] == NULL)
{
VAL = chdir(getenv("HOME"));
}
else if (str_cmp(cmd[1], "-") == 0)
{
VAL = chdir(getenv("OLDPWD"));
}
else
{
VAL = chdir(cmd[1]);
}

if (VAL == -1)
{
perror("hsh");
return (-1);
}
else if (VAL != -1)
{
getcwd(_CWD, sizeof(_CWD));
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", _CWD, 1);
}
return (0);
}

/**
 * E_disp - Enviroment display
 * @cmd: the parsed command
 * @st: the status of the last command executed.
 * Return: Always 0
 *
 */

int E_disp(__attribute__((unused)) char **cmd,
__attribute__((unused)) int st)
{
int _Len;
size_t j = 0;
/******loop*******/
while (environ[j] != NULL)
{
_Len = F_strlen(environ[j]);
write(1, environ[j], _Len);
write(STDOUT_FILENO, "\n", 1);
j++;
}

return (0);
}

/**
 * Echo_exec_bul - Echo execute cases
 * @stat_cmd: last command executed stat
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
 *
 */

int Echo_exec_bul(char **cmd, int stat_cmd)
{
unsigned int _PID = getppid();
char *_PATH;


if (F_strncmp(cmd[1], "$?", 2) == 0)
{
print_number_int(stat_cmd);
Shell_PRINT("\n");
}
else if (F_strncmp(cmd[1], "$$", 2) == 0)
{
print_number(_PID);
Shell_PRINT("\n");
}
else if (F_strncmp(cmd[1], "$PATH", 5) == 0)
{
_PATH = F_getenv("PATH");
Shell_PRINT(_PATH);
Shell_PRINT("\n");
free(_PATH);
}
else
{
return (print_echo(cmd));
}
return (1);
}

/**
 * D_History - User input display history
 * @c: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */
int D_History(__attribute__((unused))char **c, __attribute__((unused))int st)
{
char *filename = ".history";
char *Err, *_Line = NULL;
size_t len = 0;
FILE *fp;
int timer = 0;
/*******open file**************/
fp = fopen(filename, "r");
if (fp == NULL)
{
return (-1);
}

while ((getline(&_Line, &len, fp)) != -1)
{
timer++;
Err = F_itoa(timer);
Shell_PRINT(Err);
free(Err);
Shell_PRINT(" ");
Shell_PRINT(_Line);
}
if (_Line)
{
free(_Line);
}
fclose(fp);
return (0);
}
