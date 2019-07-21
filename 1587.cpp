/*
UVa:1587
给定6个矩形的长和宽(1<=wi, hi<=1000), 判断它们能否构成长方体的6个面。
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node{
    int x, y;
    node(int _x, int _y):x(_x), y(_y){}
};
bool cmp_less1(const node& _n1, const node& _n2){
    return _n1.x < _n2.x;
}

bool cmp_less2(const node& _n1, const node& _n2){
    return _n1.y < _n2.y;
}

vector<node> v_node;
map<int, int> m_indx;      

bool check_rect(){
    bool result = true;
    for(int i=0; i<v_node.size(); i+=2){
        node n1 = v_node[i];
        node n2 = v_node[i+1];
        if(n1.x != n2.x || n1.y != n2.y){
            return false;
        }
    }
    if(m_indx.size() > 3){
        return false;
    }
    for(map<int, int>::iterator iter = m_indx.begin(); iter!=m_indx.end(); iter++){
        int v = iter->second;
        if(v != 4 && v!=8 && v!= 12){
            return false;
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/1587.in", "r", stdin);
#endif
    int x, y;
    while(scanf("%d%d", &x, &y) == 2){
        if(x < y){
            v_node.push_back(node(x, y));
        }else{
            v_node.push_back(node(y, x));
        }
        m_indx[x]++;
        m_indx[y]++;

        for(int i=0; i< 5; i++){
            scanf("%d%d", &x, &y);
            m_indx[x]++;
            m_indx[y]++;
            if(x < y){
                v_node.push_back(node(x, y));
            }else{
                v_node.push_back(node(y, x));
            }
        }
        sort(v_node.begin(), v_node.end(), cmp_less2);
        sort(v_node.begin(), v_node.end(), cmp_less1);

        if(check_rect()){
            printf("POSSIBLE\n");
        }else {
            printf("IMPOSSIBLE\n");
        }
        v_node.clear();
        m_indx.clear();

    }
	return 0;
}
