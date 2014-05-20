
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3655

int DAYS[N];

void hartals(int days, int index){
	/* 公式： 
		(index-1) + 0*index;
		(index-1) + 1*index;
		(index-1) + 2*index;
		(index-1) + 3*index;
	*/
	int sum = 0, i = 0;
	while(1){
		sum = (index-1) + i * index;
		if(sum < days){
			DAYS[sum] = 1;
			i++;
		}
		else
			break;
	}
}

void remove_holiday(int days){
	int sum = 0, i=0;
	while(1){
		sum = 5 + i*7;
		if(sum < days){
			DAYS[sum] = 0;
			DAYS[sum+1] = 0;
			i++;
		}
		else
			break;
	}
}
int main(int argc, char* argv[])
{
	int cases, days, parties, i, index, sum;
#ifndef ONLINE_JUDGE
	freopen("./tests/10050.in", "r", stdin);
#endif
	scanf("%d\n", &cases);
	while(cases-- > 0){
		scanf("%d", &days);
		scanf("%d", &parties);
		memset(DAYS, 0, sizeof(DAYS));

		/* 对每个政党统计它的罢工天数*/
		for(i=0; i<parties; i++){
			scanf("%d", &index);
			hartals(days, index);
		}
		/* 删除周六，周日*/
		remove_holiday(days);

		/* 统计总的罢工天数 */
		sum = 0;
		for(i=0; i<days; i++){
			if(DAYS[i] > 0)
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

