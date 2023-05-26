#include "shell.h"


/**
 * help_for_unsetenv - printinformation on shell with unsetenv command
 *
 */
void help_for_unsetenv(void)
{
/*****help for unsetenv****/
char *message = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";
write(STDOUT_FILENO, message, F_strlen(message));
message = "environmental variable.\n\n\tUpon failure, prints a ";
write(STDOUT_FILENO, message, F_strlen(message));
message = "message to stderr.\n";
write(STDOUT_FILENO, message, F_strlen(message));
}
/**
 * display_help - print help for builtin commands
 * @command: command parsed
 * @st: Status of last command executed
 *
 * Return: 0 Success
 */
int display_help(char **command, __attribute__((unused))int st)
{
if (!command[1])
{
help_for_all();
}
else if (str_cmp(command[1], "help") == 0)
{
help_help();
}
else if (str_cmp(command[1], "env") == 0)
{
help_for_env();
}
else if (str_cmp(command[1], "alias") == 0)
{
help_for_alias();
}
else if (str_cmp(command[1], "exit") == 0)
{
help_for_exit();
}
else if (str_cmp(command[1], "setenv") == 0)
{
help_for_setenv();
}
else if (str_cmp(command[1], "unsetenv") == 0)
{
help_for_unsetenv();
}
else if (str_cmp(command[1], "cd") == 0)
{
help_for_cd();
}
return (0);
}
/**
 * help_for_env - Displays information on the shell by builtin env command
 *
 */
void help_for_env(void)
{
char *message = "env: env\n\tPrints the current environment.\n";
write(STDOUT_FILENO, message, F_strlen(message));
}
/**
 * help_for_setenv - Displays information on the shell
 * by builtin setenv command
 *
 */
void help_for_setenv(void)
{
char *message = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";
write(STDOUT_FILENO, message, F_strlen(message));
message = "environment variable, or modifies an existing one.\n\n";
write(STDOUT_FILENO, message, F_strlen(message));
message = "\tUpon failure, prints a message to stderr.\n";
write(STDOUT_FILENO, message, F_strlen(message));
}
