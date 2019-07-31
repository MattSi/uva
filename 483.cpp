/*
UVa:483
给出一段文本，将它的每个词逆序输出

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int SIZE=1024;
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/483.in", "r", stdin);
#endif
	char buf[SIZE], ch;
	int n=0;
	while( (ch = getchar()) != EOF){
		if(ch == ' ' || ch =='\n' ){
			if(n!=0){
				for(int i=n-1; i>=0; i--) putchar(buf[i]);
				n=0;
			}
			putchar(ch);
		}
		else buf[n++] = ch;
	}
	for(int i=n-1; i>=0; i--)putchar(buf[i]);
	return 0;
}
