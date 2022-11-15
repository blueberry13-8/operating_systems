#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    DIR* dirtmp = opendir("tmp");
    if (dirtmp == NULL){
        return 0;
    }
    struct dirent* dp;
    ino_t* inodes = malloc(sizeof(ino_t));
    int n = 0;
    char** names = malloc(sizeof(char*));
    struct stat* st = malloc(sizeof(struct stat));
    while ((dp = readdir(dirtmp)) != NULL){
        //printf("%s %ld %ld!!\n", dp->d_name, st->st_nlink, dp->d_ino);
        char path[1000] = "tmp/";
        strcat(path, dp->d_name);
        stat(path, st);
        ino_t inode = dp->d_ino;
        if (st->st_nlink <= 0 || strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
        }
        inodes[n] = inode;
        names[n] = malloc(sizeof(char)*1000);
        //printf("asdasdasda\n\n");
        strcpy(names[n], dp->d_name);
        n++;
        inodes = realloc(inodes, n);
        names = realloc(names, n);
    }
    FILE* out = fopen("ex4.txt", "w");
    //printf("asdasdasda\n\n");
    // for (int i = 0; i < n; i++){
    //     printf("%s \n", names[i]);
    // }
    fprintf(out, "File - Hard Links\n");
    for (int i = 0; i < n; i++){
        int m = 0;
        for (int j = 0; j < n; j++){
            if (i == j){
                continue;
            }
            if (inodes[i] == inodes[j]){
                m++;
            }
        }
        if (m <= 0){
            continue;
        }
        int m2 = 0;
        fprintf(out, "%s - ", names[i]);
        for (int j = 0; j < n; j++){
            if (i == j){
                continue;
            }
            if (inodes[i] == inodes[j]){
                fprintf(out, "%s", names[j]);
                m2++;
                if (m == m2){
                    fprintf(out, "\n");
                } else{
                    fprintf(out, ", ");
                }
            }
        }
    }

    free(dp);
    free(inodes);
    free(names);
    free(st);
    return 0;
}