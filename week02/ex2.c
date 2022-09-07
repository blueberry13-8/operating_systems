#include <stdio.h>
#include <stdlib.h>

int main(){
    char* s = malloc(sizeof(char) * 257);
    char inp = getc(stdin);
    int n = 1;
    while (inp != '.' && inp != '\n' && n < 256){
        s[n - 1] = inp;
        n++;
        inp = getc(stdin);
    }
    putc('"', stdout);
    for (int i = n - 1; i >= 0; i--){
        putc(s[i], stdout);
    }
    putc('"', stdout);
    return 0;
}
