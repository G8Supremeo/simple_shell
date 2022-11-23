#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid, my_pid, ppid;
	int status, val, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (i = 0; i <= 5; i++)
	{
		ppid = getppid();
		my_pid = getpid();
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("Child process is running with ID: %u\n", child_pid);
			printf("The ppid is: %u || The pid is: %u\n", ppid, my_pid);
			val = execve(argv[0], argv, NULL);
			if (val == -1)
			{
				perror("Error:");
				printf("Wait for me, wait for me\n");
			}
			else
			{
				wait(&status);
				printf("Oh, it's all better now\n");
			}
		}
	}
	return (0);
}
