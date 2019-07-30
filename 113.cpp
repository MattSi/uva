/*
UVa:113
给定一个整数n，一个整数p，求p的n次根
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/113.in", "r", stdin);
#endif
	double n, p;
	while(cin>>n>>p){
		printf("%.f\n", pow(p, 1.0/n));
	}
	return 0;
}
