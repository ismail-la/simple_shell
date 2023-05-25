#include "shell.h"


/**
 * help_for_unsetenv - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void help_for_unsetenv(void)
{
char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";
write(STDOUT_FILENO, msg, F_strlen(msg));
msg = "environmental variable.\n\n\tUpon failure, prints a ";
write(STDOUT_FILENO, msg, F_strlen(msg));
msg = "message to stderr.\n";
write(STDOUT_FILENO, msg, F_strlen(msg));
}

/**
 * display_help - display help for builtin commands
 * @cmd: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
if (!cmd[1])
{
help_for_all();
}
else if (str_cmp(cmd[1], "alias") == 0)
{
help_for_alias();
}
else if (str_cmp(cmd[1], "cd") == 0)
{
help_for_cd();
}
else if (str_cmp(cmd[1], "exit") == 0)
{
help_for_exit();
}
else if (str_cmp(cmd[1], "env") == 0)
{
help_for_env();
}
else if (str_cmp(cmd[1], "setenv") == 0)
{
help_for_setenv();
}
else if (str_cmp(cmd[1], "unsetenv") == 0)
{
help_for_unsetenv();
}
else if (str_cmp(cmd[1], "help") == 0)
{
help_help();
}
return (0);
}

/**
 * help_for_env - Displays information on the shell by builtin command 'env'
 */
void help_for_env(void)
{
char *msg = "env: env\n\tPrints the current environment.\n";
write(STDOUT_FILENO, msg, F_strlen(msg));
}

/**
 * help_for_setenv - Displays information on
 * the shell by builtin command 'setenv'
 */
void help_for_setenv(void)
{
char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

write(STDOUT_FILENO, msg, F_strlen(msg));
msg = "environment variable, or modifies an existing one.\n\n";
write(STDOUT_FILENO, msg, F_strlen(msg));
msg = "\tUpon failure, prints a message to stderr.\n";
write(STDOUT_FILENO, msg, F_strlen(msg));
}
