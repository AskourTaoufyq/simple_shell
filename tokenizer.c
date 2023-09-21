#include "shell.h"

/**
 * tokenizer - tokenization of the command
 * @token
 * @cmd: pointer cmd
 * Return: pointer to pointer
 **/
char **tokenizer(char *cmd)
{
	int i = 0;
	char *token;
	char **tokens;

	tokens = malloc(20 * sizeof(char *));

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
