#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char *message = malloc(sizeof(char)*1024);
    char *quit = "quit\n";
    int fd[2];
    if (pipe(fd) == -1){
        exit(-1);
    }
    //printf("%d\n", getpid());
    if (fork() == 0){
        // publisher
        // printf("%d - publisher\n", getpid());
        while (strcmp(message, quit) != 0){
            size_t s = 1024;
            getline(&message, &s, stdin);
            // printf("%d - publisher || %s", getpid(), message);
            write(fd[1], message, strlen(message));
        }
        close(fd[1]);
        exit(0);
    }
    // subscriber
    if (fork() == 0){
        // printf("%d - subscriber\n", getpid());
        while (1){
            char tmp[1024];
            read(fd[0], tmp, 1024);
            printf("Sub: %s", tmp);
        }
        close(fd[0]);
        exit(0);
    }   
    wait(NULL);
    wait(NULL);
    return 0;
}