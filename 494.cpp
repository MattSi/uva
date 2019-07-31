/*
UVa:494
数单词，一句话中有多少单词。

单词的定义为字母的序列。

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int SIZE=1024;
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/494.in", "r", stdin);
#endif
	char buf[SIZE];
	while(fgets(buf, SIZE, stdin) != NULL){
		size_t len = strlen(buf);
		int wc=0; bool in_word=false;
		for(int i=0; i<len; i++){
			if((buf[i]>='A' && buf[i]<='Z') || (buf[i]>='a' && buf[i]<='z')){
				if(!in_word){
					wc++;
					in_word=true;
				}
			}
			else{
				in_word = false;
			}
		}
		printf("%d\n", wc);
	}
	return 0;
}
