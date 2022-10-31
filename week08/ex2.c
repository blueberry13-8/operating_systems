#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    /*
    EX2 findings:
    so and si columns are always 0. I have 16GB RAM and only 100MB alocated memory doesn't influence on it. 
    P.S. I noticed that I don't have swap partition on my ubuntu.
    
    EX3 findings:
    The most usage of processor is 1%
    The most usage of memory is 0.6%
    The ex2 row go upper with more memory usage
    */
    int **a = malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++){
        a[i] = malloc(262144 * sizeof(int));
        memset(a[i], 0, 262144);
        sleep(1);
    }
    for (int i = 0; i < 10; i++){
        free(a[i]);
    }
}