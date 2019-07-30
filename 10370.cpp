/*
UVa:10370
给定一班学生的成绩，求平均线以上的百分比
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int SIZE=1024;
int scores[SIZE];

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10370.in", "r", stdin);
#endif
	int cases, N, sum;
	float avg;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &N);
		sum = 0, avg = 0.0;
		for(int i=0; i<N; i++){
			scanf("%d", &scores[i]);
			sum += scores[i];
		}
		avg = sum * 1.0/ N;
		sum = 0;
		for(int i=0; i<N; i++){
			if(scores[i] > avg) sum++;
		}
		printf("%.3f%%\n", sum*100.0/N);
	}
	return 0;
}
