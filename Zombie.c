#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(){

	pid_t pid = -1;

	pid = fork();
	assert(pid >= 0);

	if(pid == 0){
		printf("this is child %d\n", getpid());
		sleep(20);
		pthread_exit(0);
	}else{
		printf("this is parent %d\n", getpid());
		sleep(50);
		int status;
		wait(&status);
		printf("%d\n", WTERMSIG(status));
		

	}
}