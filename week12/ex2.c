#include <unistd.h>
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

int main(){
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event event;
    FILE* out = fopen("ex2.txt", "w");
    fclose(out);
    while(1){
        read(fd, &event, sizeof(event));
        if (event.type == EV_KEY){
            if (event.value == 0){
                out = fopen("ex2.txt", "a");
                fprintf(out, "RELEASED ");
                fprintf(out, "0x%04x (%d)\n", event.code, event.code);
                fclose(out);
            } else if (event.value == 1){
                out = fopen("ex2.txt", "a");
                fprintf(out, "PRESSED ");
                fprintf(out, "0x%04x (%d)\n", event.code, event.code);
                fclose(out);
            }
        }
    }
    return 0;
}
