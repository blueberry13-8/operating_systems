#include <stdio.h>
#include <stdlib.h>

struct page {
    int id;
    unsigned int r;
} typedef page;


int main(){
    int n;
    printf("Write the number of page frames: ");
    scanf("%d", &n);
    FILE* in = fopen("Lab 09 input.txt", "r");
    int pages_id[2000];
    int m = 0;
    while (fscanf(in, "%d", &pages_id[m]) != EOF){
        m++;
    }
    // Completed with reading
    // for (int i = 0; i < m; i++){
    //     printf("%d, ", pages_id[i]);
    // }
    unsigned int* ref = malloc(n*sizeof(unsigned int));
    short* used = malloc(sizeof(short) * n);
    page* frames = malloc(n*sizeof(page));
    for (int i = 0; i < n; i++){
        ref[i] = 0;//When referenced set to 1 << 31
        used[i] = 0;
    }
    int hit = 0, miss = 0;
    for (int i = 0; i < m; i++){
        short found = 0;
        for (int j = 0; j < n; j++){
            if (used[j] == 1 && frames[j].id == pages_id[i]){
                hit++;
                found = 1;
                ref[j] = 1 << 31;
            } else{
                ref[j] = 0;
            }
        }
        if (found == 0){
            miss++;
            short placed = 0;
            for (int j = 0; i < n; j++){
                if (used[j] == 0){
                    used[j] = 1;
                    frames[j].id = pages_id[i];
                    frames[j].r = 0;
                    ref[j] = 1 << 31;
                    placed = 1;
                    break;
                }
            }
            if (placed == 0){
                int k = 0;
                for (int j = 1; j < n; j++){
                    if (frames[j].r < frames[k].r){
                        k = j;
                    }
                }
                ref[k] = 1 << 31;
                frames[k].id = pages_id[i];
                frames[k].r = 0;
            }
        }
        for (int j = 0; j < n; j++){
            frames[j].r = frames[j].r >> 1;
            frames[j].r += ref[j];
        }
    }
    printf("Hit: %d, Miss: %d, Hit/Miss ratio: %f\n", hit, miss, ((float)(hit))/miss);
}