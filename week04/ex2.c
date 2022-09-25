#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;
	
	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}
	
	return result;
}


int main(void){
	const int size = 120;
	int* u = malloc(sizeof(int)*size);
	int* v = malloc(sizeof(int)*size);
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}
	const int main_pid = getpid();
	int n = 0;
	printf("Print k in console(positive integer, n = 2*k) : ");
	scanf("%d", &n);
	if (n < 1 || n > 5){
		printf("Print the right number! Run program again\n");
		return 0;
	}
	n *= 2;
	FILE* temp = fopen("temp.txt", "w");
	fclose(temp);
	for (int i = 0; i < n; i++){
		if (getpid() == main_pid){
			int pid = fork();
			if (pid == 0){
				int res = dotprod(u, v, i * (size / n), (i + 1) * (size / n));
				FILE* temp1 = fopen("temp.txt", "a");
				fprintf(temp1, "%d ", res);
				fclose(temp1);
				break;
			}
		} else{
			break;
		}
	}
	if (getpid() != main_pid){
		return 0;
	}
	for (int i = 0; i < n; i++){
		wait(NULL);
	}
	int result = 0;
	FILE* temp2 = fopen("temp.txt", "r");
	for (int i = 0; i < n; i++){
		int res;
		fscanf(temp2, "%d ", &res);
		result += res;
	}
	printf("%d\n", result);
	fclose(temp2);
	free(u);
	free(v);
	return EXIT_SUCCESS;
}

/*

Example:

Assume that
u = [u1, u2, u3, u4]
v = [v1, v2, v3, v4]
k=1 ==> n = 2 processes

Equally distribute the dot product calculation task. We have multiple ways to distribute the task equally.

1- A possible task distribution is as follows:

First process will calculate dot product for the first two components
Second process will calculate dot product for the last two components

The computation result of the first process is u1 * v1 + u2 * v2 ==> c1
The computation result of the second process is u3 * v3 + u4 * v4 ==> c2

2- Another possible distribution is as follows:

First process will calculate dot product for the even components
Second process will calculate dot product for the odd components

The computation result of the first process is u2 * v2 + u4 * v4 ==> c1
The computation result of the second process is u1 * v1 + u3 * v3 ==> c2



The file temp.txt will contain as follows: (format is not restricted)
-------------------
c1
c2
-------------------

The "main" process will aggregate all dot product computations of its children
It will read the lines and aggregate.

c1 + c2 ==> result of u * v


*/
