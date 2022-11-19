#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
  * split_string - a function that that splits a string
  * line - cmd_line strings
  * Return: an array of each word of the string
  */

char **split_string(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char *token;
	char ** Token = malloc(sizeof(char*) * bufsize);

	if (!Token)
	{
		fprintf(stderr, "lsh: memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		Token[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			Token = realloc(Token, bufsize * sizeof(char*));
			if (!Token)
			{
				fprintf(stderr, "lsh: memory reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	Token[position] =  NULL;
	return(Token);
}
