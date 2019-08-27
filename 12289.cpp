/*
UVa:12289 one-two-three
给定3个字母，其中有一个是错的，要判别是1，2，3中的某一个
=============
10
owe
too
theee
tne
owo
thfee
ono
twe
one
two
=============
1
2
3
1
2
3
1
2
1
2

*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE=64;
bool check3(char *word){
	char *target="three";
	int err=0;
	for(int i=0; i<5; i++){
		if(word[i]!=target[i])err++;
	}
	return err>1?false:true;
}

bool check2(char *word){
	char *target="two";
	int err=0;
	for(int i=0; i<3; i++){
		if(word[i] != target[i])err++;
	}
	return err>1?false:true;
}
bool check1(char *word){
	char *target="one";
	int err=0;
	for(int i=0; i<3; i++){
		if(word[i] != target[i])err++;
	}
	return err>1?false:true;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/12289.in", "r", stdin);
#endif
	int n;
	char word[SIZE];
	scanf("%d", &n);
	getchar();
	while(n--){
		fgets(word, SIZE, stdin);
		size_t len = strlen(word);
		if(word[len-1]=='\n')word[--len]='\0';
		if(len == 5){
			if(check3(word)) printf("3\n");
		}else {
			if(check2(word)) printf("2\n");
			else printf("1\n");
		}

	}
	return 0;
}
