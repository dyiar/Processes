// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

    FILE *fp;
    // Your code here 
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } else if (rc == 0) {
        fp = fopen("\\text.txt", "w+");
        fprintf(fp, "Child");
    } else {
        fp = fopen("\\text.txt", "w+");
        fprintf(fp, "Parent");
    }
    
    return 0;
}
