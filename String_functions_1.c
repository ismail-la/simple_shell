#include "shell.h"

/**
 * F_strncmp - compareNCharacters
 * @sourceString1: str1
 * @sourceString2: str2
 * @copyLength: numChars
 * Return: comparisonResult
 */
int F_strncmp(const char *sourceString1, const char *sourceString2,
size_t copyLength)
{
size_t j;
if (sourceString1 == NULL)
{
return (-1);
}
for (j = 0; j < copyLength && sourceString2[j]; j++)
{
if (sourceString1[j] != sourceString2[j])
{
return (1);
}
}
return (0);
}
/**
 * F_strchr - findCharacter
 * @sourceString: inputString
 * @ch: searchCharacter
 * Return: ptrToChar
 */
char *F_strchr(char *sourceString, char ch)
{
do {
if (*sourceString == ch)
{
break;
}
} while (*sourceString++);
return (sourceString);
}

/**
 * F_strdup - copyString
 * @stringPtr: inputString
 * Return: copyStringResult
 */
char *F_strdup(char *stringPtr)
{
size_t length, j;
char *stringPtr2;
length = F_strlen(stringPtr);
stringPtr2 = malloc(sizeof(char) * (length + 1));
if (!stringPtr2)
{
return (NULL);
}
for (j = 0; j <= length; j++)
{
stringPtr2[j] = stringPtr[j];
}
return (stringPtr2);
}

/**
 * F_strcpy - copy of string
 * @buffer: destinationString
 * @inputString: input
 *
 * Return: result
 */
char *F_strcpy(char *buffer, char *inputString)
{
int j = 0;
while (inputString[j])
{
buffer[j] = inputString[j];
j++;
}
buffer[j] = '\0';
return (buffer);
}
/**
 * F_strcat - concatStrings
 * @buffer: str1
 * @inputString: str2
 * Return: concatenatedString
 */
char *F_strcat(char *buffer, char *inputString)
{
char *sourceString = buffer;
while (*buffer != '\0')
{
buffer++;
}
while (*inputString != '\0')
{
*buffer = *inputString;
buffer++;
inputString++;
} *buffer = '\0';
return (sourceString);
}
