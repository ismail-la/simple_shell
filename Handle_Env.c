#include "shell.h"

/**
 * env_array - This function creates an array to store environment variables.
 * @array_Env: Array to store Enviroment Variables
 */

void env_array(char **array_Env)
{
int j;
/***loop******/
for (j = 0; environ[j]; j++)
{
array_Env[j] = F_strdup(environ[j]);
}
array_Env[j] = NULL;
}

/**
 * mem_free_env - This function frees the memory allocated
 * to an array of environment variables.
 * @_Env:  Array of Environment variables
 */
void mem_free_env(char **_Env)
{
int i;
/****loop*********/
for (i = 0; _Env[i]; i++)
{
free(_Env[i]);
}
}
