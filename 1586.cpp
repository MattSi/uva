/*
给出一种物质的分子式（不带括号），求分子量。
本题中的分子式只包含4中原子，
C, H, O, N， 原子量分别为

12.01, 1.008, 16.00, 14.01
Sample Input
4
C
C6H5OH
NH2CH2COOH
C12H22O11
Sample Output
12.010
94.108
75.070
342.296

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;
const int SIZE=128;

// 得到下一个token，可以是字母，可以是数字，若字符串为空，则返回-1
int get_token(char* buff, int& i, int& ttype){
	if(buff[i]=='\0'){
		ttype = -1;
		return -1;
	}
	if(isalpha(buff[i])){
		ttype = 0;
		return buff[i++];
	} 
	int res = 0;
	while(isdigit(buff[i])){
		res = res*10 + (buff[i]-'0');
		ttype = 1;
		i++;
	}
	return res;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1586.in", "r", stdin);
#endif

	char last_c = 0;
	char buff[SIZE];
	int alphabet[26];
	float mole[26] ;
	float mole_mass = 0.0;


	memset(mole, 0, sizeof(mole));
	mole[2]=12.01;
	mole[7]=1.008;
	mole[13]=14.01;
	mole[14]=16.00;

	int i, cases, val, ttype;
	scanf("%d", &cases);
	while(cases--){
		memset(buff, 0, sizeof(buff));
		memset(alphabet, 0, sizeof(alphabet));
		i=0;
		last_c = 0;
		scanf("%s", buff);
		while( (val = get_token(buff, i, ttype)) != -1){
			if(ttype == 0){
				//是一个字符（元素）
				if(last_c != 0){
					alphabet[last_c - 'A'] += 1;
				} 
				last_c = (char)val;
			} else {
				//是一个数字（元素个数）
				alphabet[last_c - 'A'] += val;
				last_c = 0;
			}
		}
		if(last_c != 0){
			alphabet[last_c - 'A'] += 1;
			last_c = 0;
		}
		mole_mass = 0.0;
		for(int i=0; i<26; i++){
			mole_mass += mole[i]*alphabet[i];
		}
		printf("%.3f\n", mole_mass);
	}

	return 0;
}
