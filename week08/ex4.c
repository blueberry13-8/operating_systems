#include <sys/resource.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    struct rusage usage;
    int **a[10];
    for (int i = 0; i < 10; i++){
        a[i] = malloc(262144 * sizeof(int));
        memset(a[i], 0, 262144);
        getrusage(RUSAGE_SELF, &usage);
        printf("ru_utime.tv_sec: %ld\n", usage.ru_utime.tv_sec);
        printf("ru_utime.tv_usec: %ld\n", usage.ru_utime.tv_usec);
        printf("ru_stime.tv_usec: %ld\n", usage.ru_stime.tv_sec);
        printf("ru_stime.tv_usec: %ld\n", usage.ru_stime.tv_usec);
        printf("ru_maxrss: %ld\n", usage.ru_maxrss);
        printf("ru_ixrss: %ld\n", usage.ru_ixrss);
        printf("ru_idrss: %ld\n", usage.ru_idrss);
        printf("ru_isrss: %ld\n", usage.ru_isrss);
        printf("ru_minflt: %ld\n", usage.ru_minflt);
        printf("ru_majflt: %ld\n", usage.ru_majflt);
        printf("ru_nswap: %ld\n", usage.ru_nswap);
        printf("ru_inblock: %ld\n", usage.ru_inblock);
        printf("ru_oublock: %ld\n", usage.ru_oublock);
        printf("ru_msgsnd: %ld\n", usage.ru_msgsnd);
        printf("ru_msgrcv: %ld\n", usage.ru_msgrcv);
        printf("ru_nsignals: %ld\n", usage.ru_nsignals);
        printf("ru_nvcsw: %ld\n", usage.ru_nvcsw);
        printf("ru_nivcsw: %ld\n\n", usage.ru_nivcsw);
        
        
        sleep(1);
    }
    for (int i = 0; i < 10; i++){
        free(a[i]);
    }
}