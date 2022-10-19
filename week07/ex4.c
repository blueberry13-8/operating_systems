#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * my_realloc(void* ptr, int size){
    if (ptr == NULL && size != 0){
        ptr = malloc(size);
    } else if (size == 0){
        free(ptr);
    } else{
        void* temp = malloc(size);
        int old_size = sizeof(ptr);
        int min = old_size;
        if (old_size > size){
            min = size;
        }
        for (int i = 0; i < min; i++){
            //temp[i] = ptr[i]; // It doesn't work
            memcpy(temp, ptr, min);
        }
        free(ptr);
        ptr = temp;
    }
    return ptr;
}

int main(){
    // Some test
    int* a = NULL;
    
    int n1 = 3;
    a = my_realloc(a, sizeof(int) * n1);
    for (int i = 0; i < n1; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    int n2 = 5;
    a = my_realloc(a, sizeof(int) * n2);
    for (int i = 0; i < n2; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    int n3 = 2;
    a = my_realloc(a, sizeof(int) * n3);
    for (int i = 0; i < n3; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    
    return 0;
}