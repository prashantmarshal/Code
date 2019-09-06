#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>

pthread_mutex_t *pmutex = NULL;
pthread_mutexattr_t attrmutex;

void synchronized_increment(int *var){
	pthread_mutex_lock(pmutex);
	(*var)++;
	pthread_mutex_unlock(pmutex);
}

void synchronized_decrement(int *var){
	pthread_mutex_lock(pmutex);
	(*var)--;
	pthread_mutex_unlock(pmutex);
}

int main(int argc, char const *argv[])
{

	pid_t pid;
	int curr_child_num; /* nth child created */
	int limit = 255; /* soft limit on number of child */

	/* Initialise attribute to mutex. */
	pthread_mutexattr_init(&attrmutex);
	pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);

	pmutex = mmap(NULL, sizeof(pthread_mutex_t), 
			PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

	pthread_mutex_init(pmutex, &attrmutex);

	/* no. of child processes created */
	int *child = mmap(NULL, sizeof(int), 
			PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	*child = 0;

	/* no. of child processes alive */
	int *child_alive = mmap(NULL, sizeof(int), 
			PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	*child_alive = INT_MAX;

	printf("Process[%d]: %d created.\n", *child, getpid());	

do_fork:
	/* number child processes created until now */
	curr_child_num = *child;

	if(curr_child_num == limit){
		printf("Process[%d]: %d could not create child."
				" Limit(%d) reached.\n", *child, getpid(), curr_child_num);
		/* setting child_alive from INT_MAX to total child created */
		*child_alive = *child; 
		goto do_not_fork;
	}

	/* create child */
	pid = fork();

	if(pid == -1){
		printf("Process[%d]: %d could not create child\n", *child, getpid());
		/* setting child_alive value from INT_MAX to
		 * no. of child processes created */
		*child_alive = *child;
	}

	if(pid == 0){
		/* Increment child count */
		synchronized_increment(child);
		printf("Child[%d]: %d created.\n", *child, getpid());
		goto do_fork;

	}else{

do_not_fork:	
		while(*child_alive > curr_child_num);
		/*sleep(1);*/
		if(curr_child_num == 0)
			printf("Process[%d]: %d exiting\n", *child_alive, getpid());
		else
			printf("Child[%d]: %d exiting\n", *child_alive, getpid());
		synchronized_decrement(child_alive);
		exit(0);
	}

}
