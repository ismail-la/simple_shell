#include "shell.h"
/**
 * fork_check_cmd - function executes predefined commands
 * by checking the given command against a predefined path.
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @cmd: Array of parsed command strings
 * @input: Input user received (to be freed).
 * @c: the Shell Excution Time state of Command Not Found
 * Return: 0 Command Excuted  1 Command Null -1 Wrong Command
 */
int fork_check_cmd(char **cmd, char *input, int c, char **argv)
{
pid_t pid_c;
int Status;
if (*cmd == NULL)
	return (EXIT_FAILURE);
pid_c = fork();
if (pid_c == -1)
	perror("Error");
	return (-1);
if (pid_c == 0)
{
if (F_strncmp(*cmd, "./", 2) != 0 && F_strncmp(*cmd, "/", 1) != 0)
	command_path(cmd);
if (access(cmd[0], R_OK) != 0)
	Error_display(cmd[0], c, argv);
	free_all(cmd, input);
	exit(127);
if (execve(*cmd, cmd, environ) == -1)
	return (2);
else
{
return (0);
}
}
wait(&Status);
if (WIFEXITED(Status))
{
if (WEXITSTATUS(Status) == 0)
	return (0);
else if (WEXITSTATUS(Status) == 127)
{
return (127);
}
else if (WEXITSTATUS(Status) == 2)
{
return (2);
}

}
return (127);
}
/**
 * Handle_signal - This function handles the SIGINT signal
 * by printing "$ " on a new line.
 * @signal: Input Signal
 */
void Handle_signal(int signal)
{
if (signal == SIGINT)
	Shell_PRINT("\n$ ");
}
