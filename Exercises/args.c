#include <stdio.h>
#include <stdlib.h>

/**
  * main - args
  * Return: Always 0
  */

int main(__attribute__((unused))int argc, char **argv)
{
	int idx;

	while(argv[idx])
	{
		printf("argv[%d]: %s\n", idx, argv[idx]);
		idx++;
	}
	return (0);
}
