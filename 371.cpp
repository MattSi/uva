#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;


int low_index, low_value;


int calc_ackman(int  a) {
	int step = 0;
	long long
		aa = a;
	while (true) {
		if ((aa % 2) == 0) {
			aa /= 2;
		}
		else {
			aa = aa * 3 + 1;
		}
		step++;
		if (aa == 1)break;
	}
	return step;
}
void ackman(int a1, int a2) {
	if (a1 > a2) return ackman(a2, a1);

	low_value = calc_ackman(a1);
	low_index = a1;
	for (int i = a1+1; i <= a2; i++) {
		int t = calc_ackman(i);
		if (t > low_value) {
			low_value = t;
			low_index = i;
		}
	}
}
int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/371.in", "r", stdin);
	//FILE *fp2 = freopen("d:\\temp\\20190824\\371.out", "w", stdout);
#endif
	int a1, a2;
	while (scanf("%d%d", &a1, &a2) == 2) {
		if (a1 == 0 && a2 == 0) break;
		ackman(a1, a2);
		//low_index = -1; low_value = -1;
		if(a1<a2)
			printf("Between %d and %d, %d generates the longest sequence of %d values.\n", a1, a2, low_index, low_value);
		else 
			printf("Between %d and %d, %d generates the longest sequence of %d values.\n", a2, a1, low_index, low_value);
	}


	return 0;
}