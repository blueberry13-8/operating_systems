#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
    DIR* dirtmp = opendir("/");
    if (dirtmp == NULL){
        return 0;
    }
    struct dirent* dp;
    while ((dp = readdir(dirtmp)) != NULL){
        printf("%s\n", dp->d_name);
    }
    free(dp);
    closedir(dirtmp);
    printf("\n");
    return 0;
}