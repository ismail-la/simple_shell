#include "shell.h"

/**
 * file_parseExec - Function that parses commands
 * and handles execution from a file.
 * @line: Line from File_name
 * @count:  Counts errors during execution.
 * @File_d: Uses a file descriptor to access the file.
 * @argv: Takes in command line arguments.
 */
void file_parseExec(char *line, int count, FILE *File_d, char **argv)
{
int stat = 0;
char **cmd;


cmd = parse_command(line);
if (F_strncmp(cmd[0], "exit", 4) == 0)
{
File_statusExit(cmd, line, File_d);
}
else if (cmd_check_builtin(cmd) == 0)
{
stat = handle_builtin(cmd, stat);
free(cmd);
}
else
{
stat = fork_check_cmd(cmd, line, count, argv);
free(cmd);
}
}
/**
 * readFD - Function reads and parses lines from
 * file using given file descriptor and exits after completion.
 * @File_name: File with commands
 * @argv: Arguments passed
 * Return: -1 on failure or 0 on success
 */

void readFD(char *File_name, char **argv)
{
char *line = NULL;
int Number = 0;
FILE *File_d;
size_t len = 0;

File_d = fopen(File_name, "r");
if (File_d == NULL)
{
Error_print_file(argv, Number);
exit(127);
}
while ((getline(&line, &len, File_d)) != -1)
{
Number++;
file_parseExec(line, Number, File_d, argv);
}
if (line)
{
free(line);
}
fclose(File_d);
exit(0);
}

/**
 * File_statusExit - The function handles exit status for file name input
 * @line: input Line from a File_name
 * @cmd: Parsed command
 * @fd: File Descriptor
 */
void File_statusExit(char **cmd, char *line, FILE *fd)
{
int k = 0;
int status;

if (cmd[k] == NULL)
{
free(line);
free(cmd);
fclose(fd);
exit(errno);
}
while (cmd[1][k])
{
if (F_isalpha(cmd[1][k++]) < 0)
{
perror("number illegal");
}
}
status = F_atoi(cmd[1]);
free(line);
free(cmd);
fclose(fd);
exit(status);
}
