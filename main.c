#include "shell.h"
/**
 * main - entry point
 * @argc: the Argument count
 * @argv: the Argument vector
 * Return: Returns status 0 on success
 */
int main(int argc, char **argv)
{
char **Sep_commands, *LineInput;
char **cmd;
int Case_stat = 0, j = 0, i, status = 1;
if (argc > 1)
	readFD(argv[1], argv);
if (argv[1] != NULL)
	readFD(argv[1], argv);
signal(SIGINT, Handle_signal);
while (status)
{
j++;
if (isatty(STDIN_FILENO))
	_prompt();
/*****Custom getline()*/
LineInput = readgetline();
if (LineInput[0] == '\0')
	continue;
F_history(LineInput);
Sep_commands = Function_separator(LineInput);
for (i = 0; Sep_commands[i] != NULL; i++)
{
cmd = parse_command(Sep_commands[i]);
if (str_cmp(cmd[0], "exit") == 0)
	free(Sep_commands);
	Status_exit__bul(cmd, LineInput, argv, j, Case_stat);
else if (cmd_check_builtin(cmd) == 0)
{
Case_stat = handle_builtin(cmd, Case_stat);
free(cmd);
continue;
}
else
	Case_stat = fork_check_cmd(cmd, LineInput, j, argv);
free(cmd);
}
free(LineInput);
free(Sep_commands);
wait(&Case_stat);
}
return (Case_stat);
}
