#ifndef _SHELL_H
#define _SHELL_H


/*** Default Libraries ***/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>


/***** Code Macros Section *****/
#define DELIMITER " \t\r\n\a"
#define SIZEBUF 1024
#define Shell_PRINT(c) (write(STDERR_FILENO, c, F_strlen(c)))
/****** Built-in Command Specification *****/
/**
 * struct _builtin - Struct definition for built-in
 * commands along with their implementation functions
 * @cmd_name: - Predefined command
 * @F: - Custom function pointer array with analogous
 * functionalities to the built-in commands
 */
typedef struct _builtin
{
char *cmd_name;
int (*F)(char **line, int st);
} F_builtin;

/*********** Memory Control Functions ***********/
/*****memory_handlers.c*********/
void *F_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
char *F_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *F_calloc(unsigned int size);

/*********************String Operations *************************************/
/******** String_functions_0.c **********/
int F_putchar(char ch);
void F_puts(char *inputString);
char *_strncpy(char *buffer, char *inputString, int copyLengh);
int F_strlen(char *sourceString);
int F_atoi(char *sourceString);
/******** String_functions_1.c **********/
char *F_strcpy(char *buffer, char *inputString);
char *F_strcat(char *buffer, char *inputString);
char *F_strchr(char *sourceString, char ch);
int F_strncmp(const char *sourceString1,
const char *sourceString2, size_t copyLength);
char *F_strdup(char *stringPtr);
/******** String_functions_2.c **********/
int str_cmp(char *sourceString1, char *sourceString2);
int F_isalpha(int ch);
char *F_itoa(unsigned int copyLength);
void array_rev(char *array, int length);
int intlen(int n);

/************************ Error Management Functions *******************/
/********error_handlers.c********/
void Error_print_custom(char **argv, int c, char **cmd);
void Error_display(char *input, int counter, char **argv);
void Error_print_file(char **argv, int b);
/*******stdin_command_execute.c******/
int fork_check_cmd(char **cmd, char *input, int c, char **argv);
void Handle_signal(int sig);


/******command_parser.c*********/
char **parse_command(char *input);

/**************************** File Input Handlers *************************/
/***file_argument_handlers.c*****/
void File_statusExit(char **cmd, char *line, FILE *fd);
void file_parseExec(char *line, int count, FILE *fp, char **argv);
void readFD(char *File_name, char **argv);

/*************************** Utility and Input Functions *********************/
/*******F_separator.c******/
char **Function_separator(char *input);
/*******history_rec.c******/
int F_history(char *input);
/******_strtok.c*******/
char *F_strtok(char *str, const char *delim);
unsigned int Delim_check(char c, const char *str);
/******prompt.c*******/
void _prompt(void);
/******Custom_getline.c*******/
char *readgetline();
char *input_NL(char *Str_Handle);
char *str_space(char *str);
void hashtag_Handler(char *In_buf);

/********************* Help Information Handlers *****************************/
/******builtin_help_handlers_2.c*******/
void help_for_env(void);
void help_for_setenv(void);
void help_for_unsetenv(void);
int display_help(char **cmd, __attribute__((unused))int st);
/******builtin_help_handlers_1.c*******/
void help_help(void);
void help_for_exit(void);
void help_for_cd(void);
void help_for_alias(void);
void help_for_all(void);

/***************** Path Explorer Functions********************************/
/******path_finder.c*******/
char *F_getenv(char *name);
char *build(char *token, char *value);
int command_path(char **cmd);

/************************ Print Utility Functions ************************/
/******printers.c*******/
int Echo_print(char **cmd);
void Number_int_print(int Num);
void Number_print(unsigned int Num);

/****************** Environment Management Functions **********************/
/****environment_handlers.c*****/
void mem_free_env(char **env);
void env_array(char **envi);
extern char **environ;

/******* Built-in Command Processors and Execution **************************/
/*****builtin_command_execute.c********/
int E_disp(__attribute__((unused)) char **cmd, __attribute__((unused)) int st);
int Dir_change(char **cmd, __attribute__((unused))int st);
int Echo_exec_bul(char **cmd, int st);
int D_History(__attribute__((unused))char **c, __attribute__((unused)) int st);
/******builtin_command_handlers.c*****/
void Status_exit__bul(char **cmd, char *input, char **argv, int c, int stat);
int handle_builtin(char **cmd, int st);
int cmd_check_builtin(char **cmd);


#endif /**_SHELL_**/
