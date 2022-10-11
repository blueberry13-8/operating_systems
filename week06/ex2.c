#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    double att = 0, awt = 0;
    int* at = malloc(sizeof(int)*n);
    int* bt = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        scanf("%d %d", at+i, bt+i);
    }
    int t = 0, executed = 0;
    while (executed < n){
        int j = 0;
        for (int i = 0; i < n; i++){
            if (bt[j] == -10 || bt[i] != -10 && at[i] <= t && (bt[i] < bt[j] || bt[i] == bt[j] && at[i] < at[j])){
                j = i;
            }
        }
        if (at[j] > t || bt[j] == -10){
            t++;
            continue;
        }
        executed++;
        awt += t - at[j];
        att += bt[j] + t - at[j];
        printf("for %d-th process CT: %d, TAT: %d, WT: %d\n", j, t + bt[j], bt[j] + t - at[j], t - at[j]);
        t += bt[j];
        bt[j] = -10;
    }
    printf("ATT: %f, AWT: %f\n", att/n, awt/n);
    return 0;
}