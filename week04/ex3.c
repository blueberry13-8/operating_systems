#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// <WRITE YOUR CODE HERE>



int main(int argc, char *argv[] ){
	if (argc == 1){
		printf("Print the argument in command line.");
		return 0;
	}
	int n = atoi(argv[1]);
	for (int i = 0; i < n; i++){
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;

}
