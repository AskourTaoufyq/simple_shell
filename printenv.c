#include "shell.h"

/**
 * printenv - prints the envirenmnt variables
 * Return: void
 **/
void printenv(void)
{
	char **env;
	unsigned int i;

	env = environ;
	i = 0;
	while (env[i] != NULL)
	{
		size_t len = strlen(env[i]);
		ssize_t bytes = write(1, env[i], len);

		if (bytes == -1)
		{
			perror("write");
			break;
		}

		bytes = write(1, "\n", 1);
		if (bytes == -1)
		{
			perror("write");
			break;
		}

		i++;
	}
}
