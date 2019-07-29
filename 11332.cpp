/*
UVa:11332
给一个整数，将它的每一位加起来。
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


int sum_digit(int n){
	int sum=0;
	while(n>0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int sum_digits(int n){
	while(n>=10){
		n = sum_digit(n);
	}
	return n;
}


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11332.in", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n) == 1 && n!=0){
		printf("%d\n", sum_digits(n));
	}
	return 0;
}
