#include "shell.h"


/**
 * F_strlen - String length determination function
 * @sourceString: Input string
 * Return: Number of characters in the string
 */
int F_strlen(char *sourceString)
{
int j;
for (j = 0; sourceString[j] != '\0'; j++)
{
continue;
}
return (j);
}
/**
 * F_atoi - String-to-integer conversion function
 * @sourceString: String input from user
 * Return: Resulting integer
 */
int F_atoi(char *sourceString)
{
int j, i = 1, n;
unsigned int m = 0;
/***loop****/
for (j = 0; sourceString[j] != '\0'; j++)
{
if (sourceString[j] == '-')
{
return (2);
}
n = sourceString[j] - '0';
if (m > 0 && !(n >= 0 && m <= 9))
break;
if (n >= 0 && n <= 9)
m = m * 10 + n;
}

m *= i;
return (m);
}


/**
 * F_putchar - Character output function
 * @ch: Character to be printed
 * Return: Character to be sent to standard output
 */
int F_putchar(char ch)
{
return (write(1, &ch, 1));
}

/**
 * F_puts - function that prints a string
 * @stringPtr: pointer to string
 * Return: void
 */
void F_puts(char *stringPtr)
{
int j;
for (j = 0; stringPtr[j] != '\0'; j++)
{
F_putchar(stringPtr[j]);
}
F_putchar('\n');
}

/**
 * _strncpy - String copying function
 * @buffer: Destination buffer
 * @inputString: Input string
 * @copyLength: Length of characters to copy
 * Return: Copied result
 */
char *_strncpy(char *buffer, char *inputString, int copyLength)
{
int j = 0;
while (j < copyLength && *(inputString + j))
{
*(buffer + j) = *(inputString + j);
j++;
}
while (j < copyLength)
{
*(buffer + j) = '\0';
j++;
}
return (buffer);
}
