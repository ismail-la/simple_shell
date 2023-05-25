#include "shell.h"

/**
 * intlen - getIntegerLength
 * @n: inputInt
 * Return: integerLength
 */
int intlen(int n)
{
int length = 0;
while (n != 0)
{
length++;
n /= 10;
}
return (length);
}

/**
 * F_itoa - intToChar
 * @copyLength: inputNum
 * Return: operateOnCharPtr
 */
char *F_itoa(unsigned int copyLength)
{
int length = 0, j = 0;
char *sourceString;
length = intlen(copyLength);
sourceString = malloc(length + 2);
if (!sourceString)
{
free(sourceString);
return (NULL);
}
*sourceString = '\0';
while (copyLength / 10)
{
sourceString[j] = (copyLength % 10) + '0';
copyLength /= 10;
j++;
}
sourceString[j] = (copyLength % 10) + '0';
array_rev(sourceString, length);
sourceString[j + 1] = '\0';
return (sourceString);
}

/**
 * str_cmp - compareStrings
 * @sourceString1: str1
 * @sourceString2: str2
 * Return: stringComparisonResult
 */


int str_cmp(char *sourceString1, char *sourceString2)
{
int compteur = 0, j, length1, length2;
length1 = F_strlen(sourceString1);
length2 = F_strlen(sourceString2);
if (sourceString1 == NULL || sourceString2 == NULL)
return (1);
if (length1 != length2)
return (1);
for (j = 0; sourceString1[j]; j++)
{
if (sourceString1[j] != sourceString2[j])
{
compteur = sourceString1[j] - sourceString2[j];
break;
}
else
continue;
}
return (compteur);
}

/**
 * array_rev - reverseArray
 * @array: arrayToReverse
 * @length: arrayLength
 */
void array_rev(char *array, int length)
{
int j = 0;
char temp;
/****loop****/
while (j < (length / 2))
{
temp = array[j];
array[j] = array[(length - 1) - j];
array[(length - 1) - j] = temp;
j++;
}

}

/**
 * F_isalpha - isAlphabeticChar
 * @ch: charToCheck
 * Return: booleanResult
 */
int F_isalpha(int ch)
{
if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
{
return (1);
}
else
{
return (0);
}
}
