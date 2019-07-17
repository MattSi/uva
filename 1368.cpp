/*
DNA序列：
输入m个长度为n的序列，求一个DNA序列，到所有序列的总的Hamming距离尽量小。
两个等长字符串的Hamming距离等于字符不同的位置个数，例如ACGT和GCGA的距离为2（左数第一个和第四个字符不同）

输入整数m和n（4<=n<=50， 4<=n<=1000），输出到m个序列的Hamming距离和最小的DNA序列和对应的距离。
如有多解，要求为字典序最小的解。
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int M = 52;
const int N = 1024;
char dnas[M][N];


char calc_col_hamming(int col_ind, int row){
	char alphabet[26];
	memset(alphabet, 0, sizeof(alphabet));
	for(int i=0; i<row; i++){
		int di = dnas[i][col_ind] - 'A';
		alphabet[di]++;
	}

	int ind = 0;
	for(int i=1; i<26; i++){
		if(alphabet[i] > alphabet[ind]){
			ind = i;
		}
	}

	return 'A'+ind;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1368.in", "r", stdin);
#endif
	int cases, m, n, hamming_dist;
	char buff[N];
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &m, &n);
		memset(dnas, 0, sizeof(dnas));
		memset(buff, 0, sizeof(buff));
		hamming_dist = 0;
		
		for(int i=0; i<m; i++){
			scanf("%s", dnas[i]);
		}
		
		for(int i=0; i<n; i++){
			buff[i] = calc_col_hamming(i, m);
			for(int j=0; j<m; j++){ //j means row, i means col
				if(dnas[j][i] != buff[i]){
					hamming_dist++;
				}
			}
		}
		printf("%s\n%d\n", buff, hamming_dist);

	}

	return 0;
}
