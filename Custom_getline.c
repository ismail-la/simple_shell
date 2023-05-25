#include "shell.h"

/**
 * readgetline - read input from STDIN
 * Return: the input on buffer
 *
 */
char *readgetline()
{
char c = 0, *buffer, *R_BUFF;
int size_buff = SIZEBUF, a, READ;


buffer = malloc(size_buff);
if (buffer == NULL)
{
free(buffer);
return (NULL);
}
for (a = 0; c != EOF && c != '\n'; a++)
{
fflush(stdin);
/**********reading*******/
READ = read(STDIN_FILENO, &c, 1);
if (READ == 0)
{
free(buffer);
exit(EXIT_SUCCESS);
}
buffer[a] = c;
if (buffer[0] == '\n')
return (input_NL(buffer));
if (a >= size_buff)
{
buffer = realloc(buffer, (size_buff + 2));
if (buffer == NULL)
{
free(buffer);
return (NULL);
}
}
}
buffer[a] = '\0';
R_BUFF = str_space(buffer);
free(buffer);
hashtag_Handler(R_BUFF);
return (R_BUFF);
}

/**
 * hashtag_Handler - function that removes everything after '#'
 * @Input_buff: input buffer
 * Return: no_void
 */
void hashtag_Handler(char *Input_buff)
{
int j;

for (j = 0; Input_buff[j] != '\0'; j++)
{
if (Input_buff[j] == '#' && Input_buff[j - 1] ==
' ' && Input_buff[j + 1] == ' ')
{
Input_buff[j] = '\0';
}
}
}
/**
 * input_NL -  newline handler
 * @Str_Handle: String to be handled
 *
 * Return: return Empty string
 */
char *input_NL(char *Str_Handle)
{
free(Str_Handle);
return ("\0");
}

/**
 * str_space - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *str_space(char *str)
{
char *buff;
int i, j = 0;

/*****allocate****/
buff = malloc(sizeof(char) * (F_strlen(str) + 1));
if (buff == NULL)
{
free(buff);
return (NULL);
}
for (i = 0; str[i] == ' '; i++)
{
;
}
for (; str[i + 1] != '\0'; i++)
{
buff[j] = str[i];
j++;
}
buff[j] = '\0';
if (buff[0] == '\0' || buff[0] == '#')
{
free(buff);
return ("\0");
}
return (buff);
}
