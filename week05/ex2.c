#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

struct Thread
{
    pthread_t *id;
    int i;
    char message[256];
};

void *func(void *param){
    struct Thread a = *((struct Thread*)(param));
    printf("id: %ld, message: %s\n", *a.id, a.message);
}

int main(){
    int n;
    scanf("%d", &n);
    pthread_t *tid = malloc(sizeof(pthread_t)*n);
    struct Thread *a = malloc(sizeof(struct Thread)*n);
    for (int i = 0; i < n; i++){
        a[i].i = i;
        char tmp[] = "Hello from thread ";
        strcpy(a[i].message, tmp);
        char tmp2[5];
        // itoa(i, tmp2, 10);
        sprintf(tmp2, "%d", i);
        strcat(a[i].message, tmp2);
        a[i].id = tid + i;
        pthread_create(tid+i, NULL, func, a + i);
        printf("Thread %d is created\n", i);
        pthread_join(tid[i], NULL);
    }

    free(tid);
    free(a);

	return EXIT_SUCCESS;
}
