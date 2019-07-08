#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]){
	int n, i, t;
	int nums[5000];
	int flags[5000], flag, ind=0;
#ifndef ONLINE_JUDGE
	freopen("./tests/10038.in", "r", stdin);
#endif
	while(scanf("%d", &n)>0){
		for(i=0; i<n; i++){
			scanf("%d", &nums[i]);
			flags[i] = 0;
		}
		flag = 1;
		ind++;
		for(i=0; i<n-1; i++){
			t = abs(nums[i] - nums[i+1]);
			if(t> (n-1) || flags[t] == 1){
				flag = 0;
				printf("Not jolly\n");
				break;
			}			
			else{
				flags[t] = 1;
			}
		}
		if(flag){
			printf("Jolly\n");
		}
	}
	return 0;
}
