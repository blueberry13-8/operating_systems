#include <unistd.h>
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>

int main(){
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    struct input_event event;
    printf("Shortcuts:\n\tP + I = I passed the Exam!\n\tC + A + P = Get some cappuccino!\n\tQ + W + E + R = Whoever moves first is a good person.\n");
    short int btn[KEY_MAX + 1];
    for (int i = 0; i < KEY_MAX + 1; i++){
        btn[i] = 0;
    }
    int cnt_pressed = 1;
    while(1){
        read(fd, &event, sizeof(event));
        if (event.type == EV_KEY){
            if (event.value == 0){
                cnt_pressed--;
                // printf("\t %d\n", cnt_pressed);
                btn[event.code] = 0;
            } else if (event.value == 1){
                if (btn[event.code] == 0){
                    btn[event.code] = 1;
                    cnt_pressed++;
                }
                // printf("! %d\n", cnt_pressed);
                if (cnt_pressed == 2 && btn[KEY_P] == 1 && btn[KEY_I] == 1){
                    printf("I passed the Exam!\n");
                } else if (cnt_pressed == 3 && btn[KEY_C] == 1 && btn[KEY_A] == 1 && btn[KEY_P] == 1){
                    printf("Get some cappuccino!\n");
                } else if (cnt_pressed == 4 && btn[KEY_Q] == 1 && btn[KEY_W] == 1 && btn[KEY_E] == 1 && btn[KEY_R] == 1){
                    printf("Whoever moves first is a good person.\n");
                }
            }
        }
    }
    return 0;
}