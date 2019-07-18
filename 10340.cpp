/*
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 9000000;

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10340.in", "r", stdin);
#endif
	char s[SIZE], t[SIZE];
	char *ps, *pt;
	memset(s, 0, sizeof(s));
	memset(t, 0, sizeof(t));
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
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
	}


	return 0;
}
