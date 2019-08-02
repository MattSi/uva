/*
UVa:11530

9宫格键盘，给定一段文字，求按照九宫格键盘需要按键多少次。
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

const int SIZE=128;
map<char, int> mp;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/11530.in", "r", stdin);
#endif
	int cases,z=0;
	char buf[SIZE], ch;
	mp.insert(pair<char, int>('a', 1));
	mp.insert(pair<char, int>('b', 2));
	mp.insert(pair<char, int>('c', 3));
	mp.insert(pair<char, int>('d', 1));
	mp.insert(pair<char, int>('e', 2));
	mp.insert(pair<char, int>('f', 3));
	mp.insert(pair<char, int>('g', 1));
	mp.insert(pair<char, int>('h', 2));
	mp.insert(pair<char, int>('i', 3));
	mp.insert(pair<char, int>('j', 1));
	mp.insert(pair<char, int>('k', 2));
	mp.insert(pair<char, int>('l', 3));
	mp.insert(pair<char, int>('m', 1));
	mp.insert(pair<char, int>('n', 2));
	mp.insert(pair<char, int>('o', 3));
	mp.insert(pair<char, int>('p', 1));
	mp.insert(pair<char, int>('q', 2));
	mp.insert(pair<char, int>('r', 3));
	mp.insert(pair<char, int>('s', 4));
	mp.insert(pair<char, int>('t', 1));
	mp.insert(pair<char, int>('u', 2));
	mp.insert(pair<char, int>('v', 3));
	mp.insert(pair<char, int>('w', 1));
	mp.insert(pair<char, int>('x', 2));
	mp.insert(pair<char, int>('y', 3));
	mp.insert(pair<char, int>('z', 4));
	mp.insert(pair<char, int>(' ', 1));
	scanf("%d", &cases);
	getchar();
	while(cases--){
		fgets(buf, SIZE, stdin);
		size_t len = strlen(buf);
		int sum = 0;
		if(buf[len-1]=='\n') buf[--len]='\0';
		for(int i=0; i<len; i++){
			map<char, int>::iterator iter = mp.find(buf[i]);
			sum += iter->second;
		}
		printf("Case #%d: %d\n", ++z, sum);
	}
	return 0;
}
