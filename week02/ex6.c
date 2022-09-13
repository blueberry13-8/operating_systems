#include <stdio.h>

int main(){
    int choice = 0;
    printf("Choose the figure : 1 - rectangle, 2 - right triangle, 3 - isosceles triangle\n");
    scanf("%d", choice);
    if (choice == 1){
        int height = 0, width = 0;
        printf("Print height and width of figure(it's two natural numbers) with space b/t them\n");
        scanf("%d %d", height, width);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                printf("*");
            }
            printf("\n");
        }
    } else if (choice == 2){
        int side1 = 0, side2 = 0;
        printf("Print length of cathetuses(it's two natural numbers) with space b/t them\n");
        scanf("%d %d", side1, side2);
        //algo
    } else if (choice == 3){
        printf("Print length of base and sides(it's two natural numbers) with space b/t them\n");
        scanf("%d %d", side1, side2);
        if (side1 + side1 <= side2){
            printf("Something goes wrong. Try to run the program again.");
            return 0;
        }
        
    } else{
        printf("Something goes wrong. Try to run the program again.");
    }
}
