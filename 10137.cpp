/*
UVa:10137   

几个大学生去旅行，每个人都付了旅费，回来后清算，求平均后最小的过手钱数.

*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int SNUM=1024;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10137.in", "r", stdin);
#endif
    int stu;
    double sum, sum_max, sum_min, costs[SNUM], avg;
    while(scanf("%d", &stu)==1 && stu!=0){
        sum = 0.0;
        for(int i=1; i<=stu; i++){
            scanf("%lf", &costs[i]);
            sum += costs[i];
        }
        avg = round(sum*100/stu)/100;
        sum_max = sum_min = 0.0;
        for(int i=1; i<=stu; i++){
            if(costs[i]>avg) sum_max += costs[i] - avg;
            else sum_min += avg-costs[i];
        }
        printf("$%.2lf\n", min(sum_max,sum_min));
    }
	return 0;
}
