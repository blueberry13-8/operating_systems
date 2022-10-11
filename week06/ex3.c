#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, q;
    printf("Write the quantum ");
    scanf("%d", &q);
    scanf("%d", &n);
    int* at = malloc(sizeof(int)*n);
    int* bt = malloc(sizeof(int)*n);
    int* bt2 = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        scanf("%d %d", at+i, bt+i);
        bt2[i] = bt[i];
    }
    int executed = 0, t = -1;
    int cnt = 0, cur = 1, max = 0;
    int* queue = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        queue[i] = 0;
    }
    int ua = q;
    double att = 0, awt = 0;
    while (executed < n){
        t++;
        for (int i = 0; i < n; i++){
            if (at[i] == t){
                queue[i] = ++max;
                cnt++;
            }
        }
        for (int i = 0; i < n; i++){
            if (queue[i] == cur){
                if (bt[i] < 1){
                    ua = q;
                    cur++;
                    queue[i] = -1;
                    printf("for %d-th process CT: %d, TAT: %d, WT: %d\n", i, t, t - at[i], t - at[i] - bt2[i]);
                    att += t - at[i];
                    executed++;
                    awt += t - at[i] - bt2[i];
                    i = -1;
                    cnt--;
                }
                else if (ua == 0){
                    cur++;
                    queue[i] += cnt;
                    max = queue[i];
                    ua = q;
                    i = -1;
                } else{
                    bt[i]--;
                    ua--;
                    break;
                }
            }
        }
    }
    printf("ATT: %f, AWT: %f\n", att/n, awt/n);
    return 0;
}