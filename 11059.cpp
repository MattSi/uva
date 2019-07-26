/*
输入n个元素组成的序列S。找出乘积最大的连续子序列。
如果这个最大乘积不是正数，则输出0
1<=n<=18, 
-10 <= S[i] <= 10
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11059.in", "r", stdin);
#endif
	int s[20], n,cases=0;
	long long ans;

	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			scanf("%d", &s[i]);
		}
		int si = 0,  fi=0;

		for(si=0; si<n; si++){
			for(fi=si; fi<n; fi++){
				long long t_ans = 1;
				for(int i=si; i<=fi; i++) t_ans *= s[i];
				if(t_ans>ans)ans = t_ans;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++cases, ans);
	}
	return 0;
}
