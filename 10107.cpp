/*
UVa:10107 不停的给出一列数，在给数的过程中不停的求其中位数

*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE=10240;
int arr[SIZE];

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10107.in", "r", stdin);
#endif
	int v, curr=0;
	while(scanf("%d", &v)==1){
		arr[curr++]=v;
		sort(arr, arr+curr);
		if(curr %2) printf("%d\n", arr[curr/2]);
		else printf("%d\n", (arr[curr/2] + arr[(curr-1)/2])/2);
	}

	return 0;
}












