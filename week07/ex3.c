#include <stdlib.h>
#include <stdio.h>


int main(){
	//Allows you to generate random number
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = realloc(a1, n2);

	for (i = n1; i < n2; i++){
        a1[i] = 0;
    }

	for(i=0; i<n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	free(a1);
    
	return 0;
}