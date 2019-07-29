/*
UVa:458
给定一段文字，解码输出。
ascii-7即可

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/458.in", "r", stdin);
#endif
	char buf[2048];
	while(fgets(buf, 2048, stdin) != NULL){
		size_t len = strlen(buf);
		if(buf[len-1] == '\n') buf[--len]='\0';
		for(int i=0; i<len; i++){
			buf[i] -= 7;
		}
		printf("%s\n", buf);
	}

	return 0;
}
