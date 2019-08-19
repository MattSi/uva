/**
UVA:146 求一个字符串的下一个排列
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/146.in", "r", stdin);
#endif
	string str;
	while (true) {
	cin >> str;
	if (str == "#") break;
	if (next_permutation(str.begin(), str.end())) cout << str << endl;
	else cout << "No Successor" << endl;
	}
}

