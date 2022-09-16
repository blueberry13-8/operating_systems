#include <stdio.h>
#include <stdlib.h>

int foo(int y){
    const int cur_year = 2022;
    return cur_year - y;
}

int main(){
    const int x = 10;
    const int* q = &x;
    const int* const p = malloc(5 * sizeof(int));
    int* const t = p;
    for (int i = 0; i < 5; i++){
        t[i] = *q;
        printf("%p %d\n", p + i, p[i]);
    }
    for (int i = 0; i < 5; i++){
        printf("Print the age : ");
        scanf("%d", &t[i]);
        t[i] = foo(t[i]);
    }
    free(p);
}
