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
    pid_t child_pid, my_pid;
    int status, val;
    char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

    my_pid = getpid();
  
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("%u\n", my_pid);
    if (child_pid == 0)
    {
    val = execve(argv[0], argv, NULL);
    if (val == -1)
    {
        perror("Error:");
    }
    printf("Wait for me, wait for me\n");
    }
    else
    {
        wait(&status);
        printf("Oh, it's all better now\n");
    }
    return (0);
}
