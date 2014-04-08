#include <stdio.h>
#include <string.h>
#define LENGTH 2048
int sum[LENGTH];

int main(int argc, char* argv[])
{
	char buf[LENGTH], tmp;
	size_t len;
	int i, bal, flow, bufi[LENGTH];
#ifndef ONLINE_JUDGE
	freopen("./tests/424.in", "r", stdin);
#endif
	memset(sum, 0, LENGTH*sizeof(int));
	while(scanf("%s", buf)>0){
		if(!strcmp(buf, "0"))break;
		len = strlen(buf);
		memset(bufi, 0, LENGTH*sizeof(int));
		for(i=0; i<len; i++){
			bufi[i]= buf[len-i-1] - '0';
		}
		flow = 0;
		for(i=0; i<LENGTH; i++){
			bal = sum[i] + bufi[i] + flow;
			sum[i] = bal % 10 ;
			flow = bal / 10;
		}		
	}
	for(i=LENGTH-1; i>=0; i--){
		if(sum[i]!=0)break;
	}
	while(i>=0)
		printf("%d", sum[i--]);
	printf("\n");
	return 0;
}
