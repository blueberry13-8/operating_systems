#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Read the data ;(
    FILE* in = fopen("input.txt", "r");
    int* E = malloc(sizeof(int));
    int n = 1;
    E[0] = 0;
    size_t N = 1000;
    char *tmp = malloc(sizeof(char)*N);
    getline(&tmp, &N, in);
    for (int i = 0; i < strlen(tmp); i++){
        if (tmp[i] == ' '){
            E = realloc(E, (++n)*sizeof(int));
            E[n - 1] = 0;
            continue;
        }
        if (tmp[i] == '\n'){
            break;
        }
        E[n - 1] = E[n - 1] * 10 + tmp[i] - '0';
    }
    // n++;
    int* A = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        fscanf(in, "%d", A+i);
    }
    int m = 0;
    int** C;
    getline(&tmp, &N, in);
    getline(&tmp, &N, in);
    while (1){
        getline(&tmp, &N, in);
        if (strlen(tmp) == 1){
            break;
        }
        C = realloc(C, sizeof(int*)*(++m));
        C[m - 1] = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++){
            int cutting = sscanf(tmp, "%d", &(C[m - 1][i])) + 1;
            for (int j = 0; j < strlen(tmp) - cutting; j++){
                tmp[j] = tmp[j + cutting];
            }
        }
    }
    int** R = malloc(sizeof(int*)*m);
    for (int i = 0; i < m; i++){
        R[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++){
            fscanf(in, "%d", &(R[i][j]));
        }
    }
    // Correctness of input values
    for (int i = 0; i < n; i++){
        int tmp1 = 0;
        for (int j = 0; j < m; j++){
            tmp1 += C[j][i];
        }
        tmp1 += A[i];
        if (E[i] != tmp1){
            for (int i = 0; i < m; i++){
                free(C[i]);
                free(R[i]);
            }
            fclose(in);
            free(C);
            free(R);
            free(tmp);
            free(A);
            free(E);
            printf("CHECK THE CORRECTNESS OF INPUT!");
            return 1;
        }
    }
    
    // Algorithm of detecting deadlocks
    short int* finish = malloc(sizeof(short int) * m);
    for (int i = 0; i < m; i++){
        finish[i] = 0;
    }
    while(1){
        short int flag = 0;
        for (int i = 0; i < m; i++){
            if (finish[i] != 0){
                continue;
            }
            short int flag_a = 1;
            for (int j = 0; j < n; j++){
                if (A[j] < R[i][j]){
                    flag_a = 0;
                    break;
                }
            }
            if (flag_a == 0){
                continue;
            }
            flag = 1;
            finish[i] = 1;
            for (int j = 0; j < n; j++){
                A[j] += C[i][j];
            }
        }
        if (flag == 0){
            break;
        }
    }

    short int win = 1;
    for (int i = 0; i < m; i++){
        if (finish[i] == 0){
            win = 0;
            printf("P%d ", i + 1);
        }
    }
    if (win == 1){
        printf("No deadlocks.");
    } else{
        printf("deadlocked.");
    }
    
    // FREEDOM
    for (int i = 0; i < m; i++){
        free(C[i]);
        free(R[i]);
    }
    free(C);
    free(R);
    free(tmp);
    fclose(in);
    free(A);
    free(E);
    free(finish);
    return 0;
}