#include "shell.h"

/**
 * main - takes a command and execute it
 * Return: integer
 **/
int main(void)
{
	int i;
	pid_t pid;
	char *cmd, **tokens;
	size_t bufferSize = 1024;

	while (1)
	{
		write(1, "$ ", 2);
		cmd = malloc(1024 * sizeof(char));
		_getline(cmd, bufferSize);
		if (cmd)
		{
			if (strcmp(cmd, "exit") == 0)
			{
				_exitshell(cmd);
			}
			tokens = tokenizer(cmd);
			pid = fork();
			if (pid == -1)
			{
			write(1, "hsh: Failed to fork the process\n", 31);
			}
			else if (pid == 0)
			{
				if (strcmp(tokens[0], "env") == 0)
					printenv();
				else
					executeCmd(tokens);
				exit(0);
			}
			else
				wait(NULL);

			for (i = 0; tokens[i] != NULL; i++)
				free(tokens[i]);
			free(tokens);
		}
		free(cmd);
	}
	return (0);
}
