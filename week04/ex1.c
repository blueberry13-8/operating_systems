#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(void){
	clock_t t_main = clock(), t1;
	int main_pid = getpid();
	int child1 = fork();
	t1 = clock();
	int child2;
	if (getpid() == main_pid) {
		child2 = fork();
		t1 = clock();
	}
	printf("pid: %d, ppid: %d\n", getpid(), getppid());
	if (getpid() == main_pid){
		printf("execution time of main process: %ld\n", clock() - t_main);
	} else{
		printf("execution time of child process: %ld\n", clock() - t1);
	}
	return EXIT_SUCCESS;
}
