#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    char* myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);
    char str[1024];
    printf("I am subscriber #%d.\n\n", atoi(argv[1]));
    while (1){
        int fd = open(myfifo, O_RDONLY);
        read(fd, str, 1024);
        sleep(1);
        printf("Publisher: %s\n\n", str);
        close(fd);
    }
    
    
}
