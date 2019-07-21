/*
UVa:10082
WERTYU:手放在键盘上，不小心就会往右错一位。
这样输入Q就会变成W，输入J就会变成K。

输入：一个错位后敲出的字符串（所有字母均大写），输出原本的句子，输入保证合法，且输入中不会出现大写字母A

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

char buff[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/10082.in", "r", stdin);
#endif
    char ch;
    while((ch=getchar())!=EOF){
        int i;
        for(i=0; buff[i] && buff[i]!=ch; i++);
        if(buff[i]) putchar(buff[i-1]);
        else putchar(ch);
    }

    return 0;
}
