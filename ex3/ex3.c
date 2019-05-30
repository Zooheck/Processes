// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        printf("Hello.\n");
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Goodbye.\n");
    }

    return 0;
}
