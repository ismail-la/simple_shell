#include "shell.h"

/**
 * Error_display - print error message
 * @user_INPUT: user input received
 * @timer: loop counter
 * @argv: Arguments before program starts
 *
 */

void Error_display(char *user_INPUT, int timer, char **argv)
{
char *error;

/******print ******/
Shell_PRINT(argv[0]);
Shell_PRINT(": ");
error = F_itoa(timer);
Shell_PRINT(error);
free(error);
Shell_PRINT(": ");
Shell_PRINT(user_INPUT);
Shell_PRINT(": not found\n");
}

/**
 *  Error_print_custom - output custom Error
 * @argv: Arguments before program starts
 * @b: Error timer
 * @cmd: Array of parsed command strings
 */

void Error_print_custom(char **argv, int b, char **cmd)
{
char *error = F_itoa(b);
/****shell print********/
Shell_PRINT(argv[0]);
Shell_PRINT(": ");
Shell_PRINT(error);
Shell_PRINT(": ");
Shell_PRINT(cmd[0]);
Shell_PRINT(": number illegal: ");
Shell_PRINT(cmd[1]);
Shell_PRINT("\n");
free(error);
}

/**
 * Error_print_file - output custom Error
 * @argv: Arguments before program starts
 * @b: Error timer
 */
void Error_print_file(char **argv, int b)
{
char *error = F_itoa(b);
/*******shell print*****/
Shell_PRINT(argv[0]);
Shell_PRINT(": ");
Shell_PRINT(error);
Shell_PRINT(": Can't open ");
Shell_PRINT(argv[1]);
Shell_PRINT("\n");
free(error);
}
