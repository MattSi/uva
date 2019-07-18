/*
 * 给定2个字符串s和t，你要决定s是不是t的子串。
 * 你可以从t中去掉一些字符得到s，但顺序不能变。
 *
 * 比如：input是 iiierernput的子串
 * 但bc不是cba的子串
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 10000000;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10340.in", "r", stdin);
#endif
	char *s, *t, *ps, *pt;
    s = (char*)malloc(SIZE*sizeof(char));
    t = (char*)malloc(SIZE*sizeof(char));
	memset(s, 0, sizeof(char)*SIZE);
	memset(t, 0, sizeof(char)*SIZE);
	while (cin >> s >> t) {
		ps = s; pt = t;
		while (*ps  && *pt ) {
			if (*ps == *pt) {
				ps++;
				pt++;
			}
			else {
				pt++;
			}
		}
		if (*ps == '\0') {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
		memset(s, 0, sizeof(char)*SIZE);
		memset(t, 0, sizeof(char)*SIZE);
	}
    
    free(s);
    free(t);

	return 0;
}
