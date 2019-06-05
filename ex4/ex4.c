// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    if (rc < 0)
    {
        printf("Failed to create new process.\n");
        exit(1);
    }
    else if (rc == 0)
    {
        char *args[] = {"/bin/ls", NULL};
        execv(args[0], args);
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Goodbye.\n");
    }
    return 0;
}