#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    printf("Print the N:");
    scanf("%d", &N);
    int *a = malloc(N*sizeof(int));
    for (int i = 0; i < N; i++){
        a[i] = i;
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}