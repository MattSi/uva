/*
UVa:10424 给定两个字符串，将字母映射成数字，再将每个数字相加，得到一个数A，将A的每一位相加，得到个位数a
求a1/a2

需要用较小的数比较大的数
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int SIZE=1024;



int get_ch_v(char c){
	if(c>='a' && c<='z'){
		return c-'a'+1;
	}
	if(c>='A' && c<='Z'){
		return c-'A'+1;
	}
	return 0;
}

int get_bit_sum(int sum){
	int sum1=0;
	while(sum>0){
		sum1 += sum%10;
		sum/=10;
	}
	return sum1;
}
int get_v(char *a){
	size_t len = strlen(a);
	int sum = 0;
	for(int i=0; i<len; i++){
		sum +=get_ch_v(a[i]);
	}

	while(sum > 9){
		sum = get_bit_sum(sum);
	}
	return sum;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10424.in", "r", stdin);
#endif
	char a[SIZE], b[SIZE];
	while(fgets(a, SIZE, stdin)!=NULL && fgets(b, SIZE, stdin)!=NULL){
		int va = get_v(a);
		int vb = get_v(b);
		double p = va*1.0/vb;
		if(p>1) p=1/p;
		//printf("a=%s, b=%s, %.2f %%\n",a,b, p*100);
		printf("%.2f %%\n", p*100);
	}
	return 0;
}
