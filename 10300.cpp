/*
UVa:10300
生态奖励,政府给农民发奖金，具体算法为农场面积大小与一个生态因子的乘积（生态因子对每个农民来说是个常数）
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10300.in", "r", stdin);
#endif
	int cases, farmer,  animal;
	long long ans, square, e_factor;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &farmer);
		ans = 0;
		for(int i=0; i<farmer; i++){
			scanf("%lld%d%lld", &square, &animal, &e_factor);
			ans += (square * e_factor);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
