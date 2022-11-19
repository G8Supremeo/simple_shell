#include <stdio.h>
#include <stdlib.h>

/**
  * main - Read a line from stdin
  * Return: 1 if success else -1
  */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *lineptr = NULL;
	ssize_t nread;
	size_t len = 0;

	printf("$ ");

	nread = getline(&lineptr, &len, stdin);

	printf("%s", lineptr);
	printf("Number of characters: %ld\n", nread);

	free(lineptr);
	exit(EXIT_SUCCESS);
}
