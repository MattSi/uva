/*
UVa:489

猜数字：计算机想一个单词让你猜，你每次可以猜一个字母，如果单词里有那个字母，所有该字母会显示出来。
如果没有那个字母，则计算机会在一幅“刽子手”画上填一笔。这幅画一共需要7笔就能完成，因此你最多能猜错6次。
注意：猜一个已经猜过的字母也算错。
本题的任务是编写一个“裁判”程序，输入单词和玩家的猜测，裁判玩家赢了，输了，还是放弃了。
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE=128;
char s[SIZE], s2[SIZE];
bool win, lose;
int chance, word_left;
void guess(char ch){
    size_t len = strlen(s);
    bool guess_wrong = true;
    for(int i=0; i<len; i++){
        if(ch == s[i]) {guess_wrong = false; s[i] = ' ';word_left--;}
    }
    if(guess_wrong) chance--;
    if(!chance) lose=true;
    if(!word_left) win = true;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/489.in", "r", stdin);
#endif
    int rnd;
    while(scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1){
        printf("Round %d\n", rnd);
        win = lose = false;
        size_t len = strlen(s2);
        word_left = strlen(s);
        chance = 7;
        for(int i=0; i<len; i++){
            guess(s2[i]);
            if(win || lose) break;
        }
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");

    }

	return 0;
}
