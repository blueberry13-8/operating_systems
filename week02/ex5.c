#include <stdio.h>

long long tribonacci(int n){
	int a = 0, b = 0, c = 1, d = 1;
	if (n == 0){
		return 0;
	} else if (n == 1 || n == 2){
		return 1;
	}
	int cnt = 2;
	while (cnt < n){
		a = b;
		b = c;
		c = d;
		d = a + b + c;
		cnt++;
	}
	return d;
}

int main(){
	printf("Answer for T(4) : %lld\n", tribonacci(4));
	printf("Answer for T(36) : %lld", tribonacci(36));
}
