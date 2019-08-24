#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int N = 1024;
int arr[N];

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10327.in", "r", stdin);
#endif
	int n, flip;
	while (scanf("%d", &n) == 1) {
		flip = 0;
		for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

		for (int i = n - 1; i > 0; i--) {
			for (int j = n-1; j > 0; j--) {
				if (arr[j] < arr[j - 1]) {
					//Flip
					int t = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = t;
					flip++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", flip);
	}


	return 0;
}