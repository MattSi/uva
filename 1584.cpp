/*
长度为n的环状串有n种表示法，分别为从某个位置开始顺时针得到。在这些表示法中，字典序最小的称为“最小表示”。

输入一个长度为n(n<=100)的环状DNA串，只包含A,C,G,T四种字符，你的任务是输出该环状串的最小表示。
例如CTCC的最小表示为CCCT,
CGAGTCAGCT的最小表示为AGCTCGAGTC

字典序：一般的，比较两个字符串，从第一个字符开始比较，当某一个位置字符不同时，该位置字符较小的串字典序较小。
其中，某一个字符串已经没有更多的字符，另一个字符串还没有结束，则较短的字符串的字典序较小。

*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

const int SIZE=128;
char buff[SIZE];

int dic_compare(int i1, int i2, int n){
	int result = 0;
	for(int i=0; i<n; i++){
		if(buff[(i1+i) % n] > buff[(i2+i) %n]){
			result = 1;
			break;
		}else if(buff[(i1+i) %n] < buff[(i2+i) %n]){
			result = -1;
			break;
		}
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1584.in", "r", stdin);
#endif

	int cases;
	size_t len;
	scanf("%d", &cases);
	while(cases--){
		scanf("%s", buff);
		len = strlen(buff);
		int _t = 0;
		for(int i=1; i<len; i++){
			if(dic_compare(_t, i, len) >0)
				_t = i;
		}

		for(int i = 0; i<len; i++){
			printf("%c", buff[ (i+_t) % len]);
		}
		printf("\n");

	}
	return 0;
}
