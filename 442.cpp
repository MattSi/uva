/*
输入N个矩阵的维度和一些矩阵链乘表达式，输出乘法的次数。
如果矩阵无法进行，则输出error。假定A是m*n矩阵，B是n*p矩阵，那么AB是m*p矩阵，乘法次数为m*n*p 
如果A的列数不等于B的行数，则乘法无法进行。
*/
 

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cctype>

using namespace std;

struct Matrix{
	int row;
	int col;
	Matrix(int _r = 0, int _c = 0){
		row = _r;
		col = _c;
	}
};

stack<Matrix> s;
Matrix m[26];
const int SIZE=2048;
long long ans;

void matrix(char *buff){
	char *p = buff;
//	if(*p == '\0') return ;
		
}


int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/442.in", "r", stdin);
#endif
	int n;
	string name;
	char buff[SIZE];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin>>name;
		int k = name[0] - 'A';
		cin>>m[k].row>>m[k].col;
	}

	while(scanf("%s", buff)!=EOF){
		ans = 0;		
		size_t len = strlen(buff);
		bool isOk = true;
		while(!s.empty())s.pop();
		for(int i=0; i<len; i++){
			if(isalpha(buff[i])) s.push(m[buff[i] - 'A']);
			else {
				if(buff[i] == ')'){
					Matrix t1 = s.top(); s.pop();
					Matrix t2 = s.top(); s.pop();
					if(t2.col != t1.row){
						isOk = false;
						break;
					}else{
						ans += t2.row * t2.col * t1.col;
						s.push(Matrix(t2.row, t1.col));
					}
				}
			}
		}
		if(isOk)cout<<ans<<"\n";
		else cout<<"error\n";

	}
	
	return 0;
}
