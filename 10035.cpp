/*
UVa:10035
给定2个数，判断相加后有多少个进位。
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int count_carry(int a, int b){
	int cn=0, c=0 , cont;
	while(a && b){
		if(((a%10) + (b%10) + c) >=10){ cn++; c=1;}
		else c=0;
		a /= 10;
		b /= 10;
	}
	if(!a) cont = b;
	else cont = a;
	while(cont){
		if( ((cont % 10) + c) >= 10){cn++; c=1;}
		else c=0;
		cont /= 10;
	}
	return cn;
}
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10035.in", "r", stdin);
#endif
	int a, b;
	while(scanf("%d%d", &a, &b)==2 ){
		if(a==0 && b==0) break;
		int ans = count_carry(a,b);
		if(ans==0)printf("No carry operation.\n");
		else if(ans == 1)printf("1 carry operation.\n");
		else printf("%d carry operations.\n", ans);
	}
	return 0;
}
