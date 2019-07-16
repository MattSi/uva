#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
const int LEN = 128;
char scores[LEN];

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1585.in", "r", stdin);
	//fp = freopen("D:\\temp\\20190716\\1585.out", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, sum=0, cont=0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		sum = 0; cont = 0;
		fgets(scores, LEN, stdin);
		size_t len = strlen(scores);
		if (len > 0 && scores[len - 1] == '\n') {
			scores[--len] = '\0';
		}
		for (size_t j = 0; j < len; j++) {
			if (scores[j] == 'X') {
				cont = 0;
			}
			else if(scores[j] =='O') {
				cont += 1;
				sum += cont;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}
