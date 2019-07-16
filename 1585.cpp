/*
得分：给出一个由O和X组成的串（长度为1-80），统计得分。
每个O的得分为目前连续出现O的个数，X的得分为0。
例如 OOXXOXXOOO的得分为1+2+0+0+1+0+0+1+2+3=10

*/

/*
Windows和Linux环境下，回车换行符是不同的。
Linux下为\n
Windows下\r\n
*/
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
