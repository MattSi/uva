/*
UVa:439

国际象棋马的移动：列用（a-h）表示，行用（1-8）表示。
求马最少需要多少步从起点跳到终点

例如a1到b2需要4步
*/



#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
const int SIZE = 8;

int board[SIZE + 1][SIZE + 1];
bool flag[SIZE + 1][SIZE + 1];
struct Node {
	int r;
	int c;
	int cnt;
	Node(int _r, int _c, int _cnt) :r(_r), c(_c), cnt(_cnt) {}
	bool operator == (const Node& n) {
		return (r == n.r && c == n.c);
	}
};
queue<Node> qs;

int dr[] = { -1, -2, -2, -1, 1, 2,  2,  1 };
int dc[] = { -2, -1,  1,  2, 2, 1, -1, -2 };

bool is_valid_move(int r, int c) {
	if (r >= 1 && r <= 8 && c >= 1 && c <= 8) return true;
	return false;
}

void tr(char* p, int& r, int& c) {
	c = p[0] - 'a' + 1;
	r = p[1] - '0';
}

void bfs(Node& s, Node& e, char* bs, char* be) {

	qs.push(s);

	while (!qs.empty()) {
		Node t = qs.front(); qs.pop();
		if (t == e) {
			printf("To get from %s to %s takes %d knight moves.\n", bs, be, t.cnt);
			break;
		}
		for (int i = 0; i < 8; i++) {
			int tr = t.r + dr[i];
			int tc = t.c + dc[i];
			if (!is_valid_move(tr, tc) || flag[tr][tc]) continue;
			else {
				flag[tr][tc] = true;
				board[tr][tc] = board[t.r][t.c] + 1;
				qs.push(Node(tr, tc, board[t.r][t.c] + 1));
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE* fp = freopen("./tests/439.in", "r", stdin);
#endif
	char bs[SIZE], be[SIZE];
	int sr, sc, er, ec;
	while (scanf("%s%s", bs, be) == 2) {
		tr(bs, sr, sc);
		tr(be, er, ec);
		if (sr == er && sc == ec) {
			printf("To get from %s to %s takes 0 knight moves.\n", bs, be);
			continue;
		}
		memset(board, 0, sizeof(board));
		memset(flag, false, sizeof(flag));
		while (!qs.empty())qs.pop();
		Node s = Node(sr, sc, 0);
		Node e = Node(er, ec, 0);
		bfs(s, e, bs, be);

	}

	return 0;
}
