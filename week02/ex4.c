#include <stdio.h>
#include <string.h>

int count(char s[], char l, int n){
    int cnt = 0;    
    if (l >= 'A' && l <= 'Z'){
        l = l - 'A' + 'a';
    }
    for (int i = 0; i < n; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
        if (s[i] == l){
            cnt++;
        }
    }
    return cnt;
}

void countAll(char s[], int n){
    for (int i = 0; i < n; i++){
        int cnt = count(s, s[i], n);
        printf("%c:%d", s[i], cnt);
        if (i != n - 1){
            printf(", ");
        }
    }
}

int main(){
    char str[256] = "";
    scanf("%s", str);
    countAll(str, strlen(str));
    return 0;
}
