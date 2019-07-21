/*
UVa:12096
有一个专门为了集合运算而设计的“集合栈”计算机。该机器有一个初始为空的栈，并支持一下操作

push：空集{}入栈
dup： 把当前栈顶元素复制一份后再入栈
union：出栈2个集合，然后把两者的并集入栈
intersect： 出栈2个集合，然后把两者的交集入栈
add： 出栈2个集合，然后把先出栈的集合加到后出栈的集合中，把结果入栈
每次操作后，输出栈顶元素的大小，即元素个数。
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("./tests/12096.in", "r", stdin);
#endif

	return 0;
}
