/*
UVa:11340 报纸

报纸给文章付稿酬，区分有用的字符与没用的字符，读入一整片文章按照有用的字符算钱
有用的字符先给出，单位是美分.

字符可能是一个负数

*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int LINE_SIZE = 10100;
const int KEY_SIZE = 300;


int key_count[KEY_SIZE], key_cent[KEY_SIZE];
char line[LINE_SIZE];

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11340.in", "r", stdin);
#endif
	int cases, cent;
	char ch[10];
	scanf("%d", &cases);
	while(cases--){
		int ksize, lsize;
		long long sum=0;
		memset(key_count, 0, sizeof(key_count));
		memset(key_cent, 0, sizeof(key_cent));
		scanf("%d", &ksize);
		while(ksize--){
			scanf("%s%d", ch, &cent);
			key_cent[ch[0]]=cent;
		}
		scanf("%d", &lsize);
		getchar();
		while(lsize--){
			fgets(line, LINE_SIZE, stdin);
			size_t len = strlen(line);
			if(line[len-1] == '\n') line[--len]='\0';
			for(int i=0; i<len; i++){
				key_count[line[i]]++;
			}
		}
		for(int i=0; i<KEY_SIZE; i++){
			sum += key_count[i] * key_cent[i];
		}
		printf("%.2f$\n", sum/100.0);

	}
	return 0;
}












