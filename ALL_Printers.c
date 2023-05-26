#include "shell.h"

/**
 * Number_int_print - This function prints integers using
 * the _putchar function.
 * @Num: Integer The integer to be printed is passed as the parameter Num.
 *
 */
void Number_int_print(int Num)
{
unsigned int b = Num;
if (Num < 0)
{
F_putchar('-');
b = -b;
}
if ((b / 10) > 0)
{
Number_print(b / 10);
}
F_putchar(b % 10 + '0');
}

/**
 * Number_print -  The name of the function that prints
 * unsigned integers using _putchar function.
 * @Num:  Passes an unsigned integer as a parameter to the function.
 *
 */
void Number_print(unsigned int Num)
{
unsigned int b = Num;
if ((b / 10) > 0)
Number_print(b / 10);
F_putchar(b % 10 + '0');
}

/**
 * Echo_print -  This function executes the built-in echo command.
 * @cmd: the Command parsed
 *
 * Return:  0 if successful and -1 if unsuccessful.
 */
int Echo_print(char **cmd)
{
int Stat;
pid_t _PID;

_PID = fork();
if (_PID == 0)
{
if (execve("/bin/echo", cmd, environ) == -1)
{
return (-1);
}
exit(EXIT_FAILURE);
}
else if (_PID < 0)
{
return (-1);
}
else
{
do {
waitpid(_PID, &Stat, WUNTRACED);
} while (!WIFEXITED(Stat) && !WIFSIGNALED(Stat));
}
return (1);
}
