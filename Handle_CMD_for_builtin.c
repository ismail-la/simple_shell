#include "shell.h"

/**
 * cmd_check_builtin - Check if the parsed command is a built-in.
 * @cmd: Take the parsed command as input.
 * Return: 0 for success and -1 for failure.
 */
int cmd_check_builtin(char **cmd)
{
	F_builtin fun[] = {
		{"help", NULL},
		{"cd", NULL},
		{"env", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
int i = 0;

if (*cmd == NULL)
{
return (-1);
}
while ((fun + i)->cmd_name)
{
if (str_cmp(cmd[0], (fun + i)->cmd_name) == 0)
{
return (0);
}
i++;
}
return (-1);
}

/**
 * handle_builtin - function manages built-in commands.
 * @cmd: Array of parsed command strings
 * @status: Status of previous execution
 * Return:  0 for success and -1 for failure.
 */
int handle_builtin(char **cmd, int status)
{
F_builtin built_in[] = {
		{"help", display_help},
		{"cd", Dir_change},
		{"env", E_disp},
		{"echo", Echo_exec_bul},
		{"history", D_History},
		{NULL, NULL}
};

int j;
/*****loop*****/
for (j = 0; (built_in + j)->cmd_name; j++)
{
if (str_cmp(cmd[0], (built_in + j)->cmd_name) == 0)
{
return ((built_in + j)->F(cmd, status));
}
}

return (-1);
}

/**
 * Status_exit__bul - Describes the exit status for built-in commands.
 * @cmd: parsed command strings array
 * @input: user input (to be freed)
 * @argv: Arguments before program starts
 * @c: Shell execution count
 * @stat: Exit status
 */
void Status_exit__bul(char **cmd, char *input, char **argv, int c, int stat)
{
int _Status, j = 0;

if (cmd[1] == NULL)
{
free(input);
free(cmd);
exit(stat);
}
while (cmd[1][j])
{
if (F_isalpha(cmd[1][j++]) != 0)
{
Error_print_custom(argv, c, cmd);
free(input);
free(cmd);
exit(2);
}
else
{
_Status = F_atoi(cmd[1]);
if (_Status == 2)
{
Error_print_custom(argv, c, cmd);
free(input);
free(cmd);
exit(_Status);
}
free(input);
free(cmd);
exit(_Status);
}
}
}
