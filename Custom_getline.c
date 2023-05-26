#include "shell.h"

/**
 * readgetline - read input from STDIN
 * Return: the input on buff
 *
 */
char *readgetline()
{
char b = 0, *buff, *R_BUFF;
int size_buff = SIZEBUF, READ;
int a = 0;
buff = malloc(size_buff);
if (buff == NULL)
{
free(buff);
return (NULL);
}
/*********loop**********/
while (b != EOF && b != '\n')
{
fflush(stdin);

/**********reading*******/
READ = read(STDIN_FILENO, &b, 1);
if (READ == 0)
{
free(buff);
exit(EXIT_SUCCESS);
}
buff[a] = b;
if (buff[0] == '\n')
return (input_NL(buff));
if (a >= size_buff)
{
buff = realloc(buff, (size_buff + 2));
if (buff == NULL)
{
free(buff);
return (NULL);
}
}
a++;
}
buff[a] = '\0';
R_BUFF = str_space(buff);
free(buff);
hashtag_Handler(R_BUFF);
return (R_BUFF);
}
/**
 * hashtag_Handler - function that removes everything after #
 * @In_buf: input buffer
 * Return: no_void
 */
void hashtag_Handler(char *In_buf)
{
int j;

for (j = 0; In_buf[j] != '\0'; j++)
{
if (In_buf[j] == '#' && In_buf[j - 1] == ' ' && In_buf[j + 1] == ' ')
{
In_buf[j] = '\0';
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
;
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
