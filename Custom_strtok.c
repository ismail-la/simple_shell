#include "shell.h"

/**
 * Delim_check - checks if a character
 * matchs any character
 * @ch: character to check
 * @delim_str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int Delim_check(char ch, const char *delim_str)
{
unsigned int i = 0;
/*****loop*******/
while (delim_str[i] != '\0')
{
if (ch == delim_str[i])
{
return (1);
}
i++;
}
return (0);
}

/**
 * F_strtok - splits a string into words or
 * extracts tokens of a string
 * @string: the input string
 * @d: the delimiter string
 * Return: pointer to next token or NULL
 */
char *F_strtok(char *string, const char *d)
{
unsigned int j;
static char *Tokens;
static char *TokenNew;


if (string != NULL)
{
TokenNew = string;
}
Tokens = TokenNew;
if (Tokens == NULL)
{
return (NULL);
}
for (j = 0; Tokens[j] != '\0'; j++)
{
if (Delim_check(Tokens[j], d) == 0)
{
break;
}
}
if (TokenNew[j] == '\0' || TokenNew[j] == '#')
{
TokenNew = NULL;
return (NULL);
}
Tokens = TokenNew + j;
TokenNew = Tokens;
for (j = 0; TokenNew[j] != '\0'; j++)
{
if (Delim_check(TokenNew[j], d) == 1)
{
break;
}
}
if (TokenNew[j] == '\0')
{
TokenNew = NULL;
}
else
{
TokenNew[j] = '\0';
TokenNew = TokenNew + j + 1;
if (*TokenNew == '\0')
{
TokenNew = NULL;
}
}
return (Tokens);
}
