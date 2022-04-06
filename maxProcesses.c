#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main(int argc, char *argv[]) {
        int pid;
        int pidCount;
        for(;;) {
                pid = fork();
                if(pid == 0) {break;}
                else if(pid > 0) {
                        pidCount++;
                        printf("PID COUNT IS: %d and PID is: %d\n", pidCount, pid);
                } else {
                        printf("FORK ERROR %d\n", pidCount);
                        break;
                }
        }
}
