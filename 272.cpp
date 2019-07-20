/*
UVa:272
Tex中的引号：在TEX中，左双引号是``,右双引号是''，输入一篇包含双引号的文章，你的任务是把它转为Tex格式。

*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/272.in", "r", stdin);
#endif
	bool first_quote = true;
	char ch;
	while((ch = getchar()) != EOF){
		if(ch == '"'){
			if(first_quote){
				printf("``");
				first_quote = false;
			}else{
				printf("''");
				first_quote = true;
			}

		} else {
			putchar(ch);
		}
	}
	return 0;
}
