/*
从左到右有n个木块，  0, 1, ..., n-1
模拟以下4种操作
1. move a onto b  : a,b上方的木块全部归位，把a放到b的上面。
2. move a over b  : a上方的木块全部归位，把a放到b所在的木块堆的顶部。
3. pile a onto b  : b上方的木块全部归位，然后把a以及上方的木块整体摞在b上。
4. pile a over b  : 把a以及上面的木块整体摞在b所在木块堆的顶部。

quit终止一组数据。
a和b在同一堆的指令是非法指令，需要忽略。

*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 30;
int n;
vector<int> blocks[maxn];

void print();
void find_block(int v, int& slot, int& high);
void reset_block(int ind, int h);
void pile_block(int inda, int ha, int indb);

int main(int argc, char **argv){
	int a, b, i;
	string s1, s2;
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/101.in", "r", stdin);
#endif
	cin>>n;
	for(i=0; i<n; i++)blocks[i].push_back(i);
	i=0;
	while(cin>>s1>>a>>s2>>b){
		int inda, ha, indb, hb;
		if(s1 == "quit")break;
		find_block(a, inda, ha);
		find_block(b, indb, hb);
		if(inda == indb) continue; //非法指令， 忽略
		if(s1 == "move")
			reset_block(inda, ha);
		if(s2 == "onto")
			reset_block(indb, hb);
		pile_block(inda, ha, indb);
	}
	
	print();
	return 0;
}

// 将a以及上面的木块，整体摞在b所在木块堆的顶部
void pile_block(int inda, int ha, int indb){
	for(int i=ha; i<blocks[inda].size(); i++){
		int v = blocks[inda][i];
		blocks[indb].push_back(v);
	}
	blocks[inda].resize(ha);
}

void print(){
	for(int i=0; i<n; i++){
		printf("%d:", i);
		for(int j=0; j<blocks[i].size(); j++){
			printf(" %d", blocks[i][j]);
		}
		printf("\n");
	}
}

// 找出给定的木块，在哪个槽，多高
void find_block(int v, int& slot, int& high){
	for(slot=0; slot<n; slot++){
		for(high=0; high<blocks[slot].size(); high++){
			if(blocks[slot][high] == v) return;
		}
	}
}

//将序号为ind, 高度为h上方的木块归位
void reset_block(int ind, int h){
	for(int i=h+1; i<blocks[ind].size(); i++){
		int v = blocks[ind][i];
		blocks[v].push_back(v);
	}
	blocks[ind].resize(h+1);
}


