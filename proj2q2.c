#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
int x =7;
int Pid = 2;
int Pid2 = 2;
printf("start with PID %d\n",getpid());
int rootpid = getpid();
printf("create child B\n");
Pid = fork();
sleep(x);
if(Pid!=0){
printf("create child C\n");
}else{
printf("create child D\n");
}
Pid2=fork();
sleep(x);
if(Pid2!=0){
	if(Pid!=0){
	printf("A (pid %d) is waiting for children\n", getpid());
	}else{
	printf("B (pid %d) is waiting for children\n",getpid());
	}
	wait(NULL);
	if(Pid!=0){
		printf("A is waiting for B to terminate\n");
		wait(NULL);
		sleep(x);
		printf("A is terminated\n");
		exit(2);
	}else{
		sleep(x);
		printf("B is terminated\n");
		exit(4);
	}
}else{
	char pidd[10];
	if(Pid==0){
		printf("D has pid %d\n",getpid());
		sleep(x);
		printf("D is terminated\n");
		exit(10);
	}else{
		printf("C has pid %d\n",getpid());
		sleep(1);
		int pid3 = fork();
		if(pid3==0){
		sprintf(pidd, "%d", getppid());
			execl("/bin/pstree", "pstree", "-p", pidd, (char*)0);
		}
		wait(NULL);
		sleep(x);
		printf("C is terminated\n");
		exit(8);
	}
}
}

