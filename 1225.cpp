/*
数数字：把前n (n<=10000 ), 个整数顺次写在一起，12345678910111213141516...数一数0-9各出现多少次
（输出10个整数，分别是0，1，..., 9的个数）


第一行输入n，代表有n行
Sample Input
2
3
13
Sample Output
0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 1
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1225.in", "r", stdin);
#endif
	int cases, n;
	char buff[8];
	int num[10];
	scanf("%d", &cases);
	for(int c=0; c<cases; c++){
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for(int i=1; i<=n; i++){
			int number = i;
			while(number>0){
				int t = number%10;
				num[t]++;
				number /= 10;
			}
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9]); 
	}

	return 0;
}
