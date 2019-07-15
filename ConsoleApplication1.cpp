

//#include "pch.h"
#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <deque>
#include <map>

using namespace std;

struct CMD {
	int id;
	char c;
	int quant;
	int price;
	bool valid;
	bool traded;
	CMD(int _id, int _c, int _quant, int _price, bool _valid, bool _traded) :
		id(_id), c(_c), quant(_quant), price(_price), valid(_valid), traded(_traded) {}
};

struct cmp_less {
	bool operator()(CMD*  c1, CMD*  c2) {
		return c1->price < c2->price;
	}
};

struct cmp_more {
	bool operator()(CMD*  c1, CMD*  c2) {
		return c1->price > c2->price;
	}
};

int n;
priority_queue<CMD*, vector<CMD*>, cmp_less> buy_queue;
priority_queue<CMD*, vector<CMD*>, cmp_more> sell_queue;
map<int, CMD*> id_map;
map<int, int> buy_cnt;
map<int, int> sell_cnt;


void update_cnt(char ins, int price, int quant);
void find_trade(char trigger);
void print_quote();

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	FILE *fp = freopen("d:\\temp\\20190715\\1598.in", "r", stdin);
	fp = freopen("d:\\temp\\20190715\\1598.out", "w", stdout);
#endif
	while (scanf("%d\n", &n) == 1) {
		while (!buy_queue.empty())buy_queue.pop();
		while (!buy_queue.empty())sell_queue.pop();
		id_map.clear();
		buy_cnt.clear();
		sell_cnt.clear();

		char inst[8];
		int quant, price;
		for (int i = 1; i <= n; i++) {
			if (scanf("%s %d %d\n", inst, &quant, &price) == 3) {
				CMD *c = new CMD(i, toupper(inst[0]), quant, price, true, false);
				id_map.insert(pair<int, CMD*>(i, c));
				switch (inst[0]) {
				case 'b':
				case 'B':
					update_cnt('B', price, quant);
					buy_queue.push(c);
					find_trade('B');
					break;
				case 's':
				case 'S':
					update_cnt('S', price, quant);
					sell_queue.push(c);
					find_trade('S');
					break;
				default:
					break;
				}
			}
			else {
				CMD* cmd = id_map.at(quant); //quant在这里等于要取消的交易id
				if (!cmd->traded) {
					cmd->valid = false;
					if (cmd->c == 'B') update_cnt('B', cmd->price, cmd->quant * -1);
					else update_cnt('S', cmd->price, cmd->quant * -1);
				}
			}
			print_quote();
		}
	}
	return 0;
}


void find_trade(char trigger) {
	while (!sell_queue.empty() && !buy_queue.empty()) {
		CMD* lowest_sell = sell_queue.top();
		if (!lowest_sell->valid) {
			sell_queue.pop();
			continue;
		}
		CMD* highest_buy = buy_queue.top();
		if (!highest_buy->valid) {
			buy_queue.pop();
			continue;
		}
		if (lowest_sell->price <= highest_buy->price) {
			int low_quant = min(lowest_sell->quant, highest_buy->quant);
			lowest_sell->quant -= low_quant;
			highest_buy->quant -= low_quant;
			lowest_sell->traded = highest_buy->traded = true;
			if (trigger == 'B') {
				printf("TRADE %d %d\n", low_quant, lowest_sell->price);
			}
			else {
				printf("TRADE %d %d\n", low_quant, highest_buy->price);
			}
			update_cnt(lowest_sell->c, lowest_sell->price, low_quant * -1);
			update_cnt(highest_buy->c, highest_buy->price, low_quant * -1);
			if (lowest_sell->quant == 0) sell_queue.pop();
			if (highest_buy->quant == 0) buy_queue.pop();
		}
		else {
			break;
		}
	}
}

void update_cnt(char ins, int price, int quant) {
	map<int, int>::iterator iter;
	if (ins == 'B') {
		iter = buy_cnt.find(price);
		if (iter != buy_cnt.end()) {
			int tmp_q = buy_cnt[price];
			buy_cnt[price] = quant + tmp_q;
		}
		else {
			buy_cnt[price] = quant;
		}

		if (buy_cnt[price] == 0) {
			buy_cnt.erase(price);
		}
	}
	else { //(ins == 'S')
		iter = sell_cnt.find(price);
		if (iter != sell_cnt.end()) {
			int tmp_q = sell_cnt[price];
			sell_cnt[price] = quant + tmp_q;
		}
		else {
			sell_cnt[price] = quant;
		}
		if (sell_cnt[price] == 0) {
			sell_cnt.erase(price);
		}
	}
}

void print_quote() {

	int buy_price = 0, buy_quant = 0, sell_price = 99999, sell_quant = 0;
	map<int, int>::iterator iter;

	while (!buy_queue.empty()) {
		CMD *b_order = buy_queue.top();
		if (!b_order->valid) buy_queue.pop();
		else break;
	}	
	if (!buy_queue.empty()){
		CMD *b_order = buy_queue.top();
		iter = buy_cnt.find(b_order->price);
		if (iter != buy_cnt.end()) {
			buy_price = b_order->price;
			buy_quant = buy_cnt[buy_price];
		}		
	}
	
	while (!sell_queue.empty()) {
		CMD *s_order = sell_queue.top();
		if (!s_order->valid) sell_queue.pop();
		else break;
	}
	if (!sell_queue.empty()) {
		CMD *s_order = sell_queue.top();
		iter = sell_cnt.find(s_order->price);
		if (iter != sell_cnt.end()) {
			sell_price = s_order->price;
			sell_quant = sell_cnt[sell_price];
		}
	}

	printf("QUOTE %d %d - %d %d\n", buy_quant,  buy_price, sell_quant, sell_price );
	
}

