// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int returnCode = fork();
    if (returnCode < 0)
    {
        printf("Failed to create new process.\n");
        exit(1);
    }
    else if (returnCode == 0)
    {
        printf("This is the child.\n");
        x = 0;
        printf("X is %d\n", x);
    }
    else
    {
        printf("This is the parent.\n");
        x = 7;
        printf("X is %d\n", x);
    }

    return 0;
}
