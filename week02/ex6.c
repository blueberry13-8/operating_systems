#include <stdio.h>

int main(){
    int choice = 0;
    printf("Choose the figure : 1 - rectangle, 2 - right triangle, 3 - isosceles triangle\n");
    scanf("%d", &choice);
    if (choice == 1){
        int height = 0, width = 0;
        printf("Print height and width of figure(it's two natural numbers) with space b/t them\n");
        scanf("%d %d", &height, &width);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                printf("*");
            }
            printf("\n");
        }
    } else if (choice == 2){
        int side;
        printf("Print length of cathetuses(it's one natural number)\n");
        scanf("%d", &side);
        for (int i = 0; i < side; i++){
            for (int j = 0; j < i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
    } else if (choice == 3){
        int side = 0;
        printf("Print length of base(it's one natural numbers)\n");
        scanf("%d", &side);
        for (int i = 0; i < side; i++){
            int n = i + 1;
            if (n * 2 > side){
                n = side - i;
            }
            for (int j = 0; j < n; j++){
                printf("*");
            }
            printf("\n");
        }
    } else{
        printf("Something goes wrong. Try to run the program again.");
    }
}
