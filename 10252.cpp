/*
UVa:10252
给定2个小写字符串str1, str2

求一个最长的子串s，它既是str1的字串的排列，又是str2子串的排列。

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE=1024;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10252.in", "r", stdin);
#endif
	char buf1[SIZE],buf2[SIZE], sub[SIZE];
	size_t len1, len2;
	int i1, i2, isub;
	while(fgets(buf1, SIZE, stdin)!=NULL && fgets(buf2,SIZE, stdin)!=NULL){
		len1 = strlen(buf1); len2 = strlen(buf2); memset(sub, 0, SIZE);
		if(buf1[len1-1]=='\n') buf1[--len1]='\0';
		if(buf2[len2-1]=='\n') buf2[--len2]='\0';
		sort(buf1, buf1+len1); sort(buf2, buf2+len2);

		i1 = i2 = isub = 0;
		printf("%s\n", buf1);
		printf("%s\n", buf2);
	}
	return 0;
}
