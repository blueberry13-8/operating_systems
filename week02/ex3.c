#include <stdio.h>
#include <math.h>
#include <string.h>

void convert(int s, int t, char number[]){
	if (s < 2 || s > 10 || t < 2 || t > 10){
	    printf("cannot convert!");
		return;
	}
	int n = strlen(number);
	long long num10 = 0, power = 1;
	for (int i = n - 1; i >= 0; i--){
		int digit = number[i] - '0';
		num10 += digit * power;
		power *= s;
		if (digit < 0 || digit >= s){
			printf("cannot convert!");
			return;
		}
	}
	char result[1000] = "";
	n = 0;
	while (num10 >= t){
		result[n] = (num10 % t) + '0';
		num10 /= t;
		n++;
	}
	result[n] = num10 + '0';
	for (int i = 0; i < strlen(result) / 2; i++){
	    char temp = result[i];
	    result[i] = result[strlen(result) - 1 - i];
	    result[strlen(result) - 1 - i] = temp;
	}
	printf("%s", result);
}

int main(){
    int s, t;
    char number[1000] = "";
    scanf("%s %d %d", number, &s, &t);
    convert(s, t, number);
    return 0;
}
