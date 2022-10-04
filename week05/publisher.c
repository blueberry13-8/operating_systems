#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]){
    char* myfifo = "/tmp/ex1";
    int num = atoi(argv[1]);
    mkfifo(myfifo, 0666);
    char* s = malloc(sizeof(char) * 1024);
    printf("I am Publisher.\n\n");
    while(1){
        int fd = open(myfifo, O_WRONLY);
        size_t n = 1024;
        getline(&s, &n, stdin);

        printf("\n");
        for (int i = 0; i < num; i++){
            write(fd, s, strlen(s));
        }
        close(fd);
        sleep(1);
    }
}
