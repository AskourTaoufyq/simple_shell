#include "shell.h"

/**
 * _exitshell - exit with error number
 * @cmd: command to free
 * Return: void
 **/
void _exitshell(char *cmd)
{
	free(cmd);
	exit(0);
}
