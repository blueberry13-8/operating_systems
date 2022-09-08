#include <stdio.h>
#include <math.h>

long long convert(int s, int t, long long number){
	int digit_amount = log10(number) + 1;
	long long num10 = 0, power = 1;
	for (int i = 0; i < digit_amount; i++){
		int digit = number % 10;
		number /= 10;
		num10 += digit * power;
		power *= s;
		if (digit >= s){
			return -1;
		}
	}
	long long result = 0;
	number = 1;
	while (num10 >= t){
		result += (num10 % t) * number;
		num10 /= t;
		number *= 10;
	}
	result += num10 * number;
	return result;
}

int main(){
    int s, t;
    long long number;
    scanf("%lld %d %d", &number, &s, &t);
    long long result = convert(s, t, number);
    if (result != -1){
	    printf("%lld", result);
	} else{
		printf("cannot convert!");
	}
    return 0;
}
