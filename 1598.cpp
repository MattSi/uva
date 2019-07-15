/*
 * 为交易所设计一个订单处理系统。要求支持以下3种指令
 * 1. BUY p q: 有人想买，数量为p，价格为q
 * 2. SELL p q:有人想卖，数量为p，价格为q
 * 3. CANCEL i:取消第i条指令对应的订单（输入保证该指令是BUY或者SELL）
 *
 * 交易规则如下： 对于当前买订单，若当前最低卖价（ask price）低于当前出价，则发生交易。
 *                对于当前卖订单，若当前最高买价（bid price）高于当前价格，则发生交易。
 *                发生交易时，按供需物品的个数的最小值交易。
 *                交易后，需修改订单的供需物品个数。
 *                当出价和价格相同时，按订单产生的先后顺序发生交易
 * 细节见UVa1598
 *
 *
 */

#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>


using namespace std;

struct CMD{
    int id;
	char c;
    int quant;
    int price;
    bool valid;
    CMD(int _id, int _c, int _quant, int _price, bool _valid):
        id(_id), c(_c), quant(_quant), price(_price), valid(_valid){}
};

struct cmp_less{
    bool operator()(CMD c1, CMD c2){
        return c1.price <= c2.price;
    }
};

struct cmp_more{
    bool operator()(CMD c1, CMD c2){
        return c1.price >= c2.price;
    }
};

int n;
priority_queue<CMD, vector<CMD>, cmp_less> buy_queue;
priority_queue<CMD, vector<CMD>, cmp_more> sell_queue;
map<int, CMD*> id_map;
map<int, int> buy_cnt;
map<int, int> sell_cnt;


void update_cnt(char ins, int price, int quant);
void find_trade(char trigger);
void print_quote();

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    FILE *fp = freopen("./tests/1598.in", "r", stdin);
#endif
    while(scanf("%d\n", &n)==1){
        while(!buy_queue.empty())buy_queue.pop();
        while(!buy_queue.empty())sell_queue.pop();
        id_map.clear();
        buy_cnt.clear();
        sell_cnt.clear();

        char inst[8];
        int quant, price;
        for(int i=1; i<=n; i++){
            if(scanf("%s %d %d\n", inst, &quant, &price) == 3){
                CMD *c = new CMD(i, toupper(inst[0]), quant, price, true);
                id_map.insert(pair<int, CMD*>(i, c));
                switch(inst[0]){
                    case 'b':
                    case 'B':
                        update_cnt('B', price, quant); 
                        buy_queue.push(*c);
                        find_trade('B');
                        break;
                    case 's':
                    case 'S':
                        update_cnt('S', price, quant); 
                        sell_queue.push(*c);
                        find_trade('S');
                        break;
                    default:
                        break;
                }
            }else {
                CMD* cmd = id_map.at(quant); //quant在这里等于要取消的交易id
                cmd->valid = false;
				if(cmd->c == 'B') update_cnt('B', cmd->price, cmd->quant);
                else update_cnt('S', cmd->price, cmd->quant);
            }
            print_quote();
        }
    }
    //CMD *c = new CMD(1,100, 35, true);
    //buy_queue.push(*c);
    //id_map.insert(pair<int, CMD*>(1, c));
    /*
    buy_queue.push(*new CMD(1, 100, 35, true));
    buy_queue.push(*new CMD(2, 100, 34, true));
    buy_queue.push(*new CMD(3, 100, 32, true));
    buy_queue.push(*new CMD(4, 100, 36, true));
    buy_queue.push(*new CMD(5, 100, 35, true));

    while (!buy_queue.empty()){
        printf("ID: %5d, PRICE: %5d\n", buy_queue.top().id, buy_queue.top().price);
        buy_queue.pop();
    }
*/
    //CMD* cmd = id_map.at(1);
    //cout<<id_map.at(1)->price<<endl;
    return 0;
}


// 在买入、卖出队列中寻找可能的交易
void find_trade(char trigger){
	while(!sell_queue.empty() && !buy_queue.empty()){
		CMD lowest_sell = sell_queue.top();
		CMD highest_buy = buy_queue.top();
		if(lowest_sell.price <= highest_buy.price){
			//最小份额，发生交易
			int low_quant = min(lowest_sell.quant, highest_buy.quant);
			lowest_sell.quant -= low_quant;
			highest_buy.quant -= low_quant;
			if(trigger == 'B'){
				// 对于当前买订单，若当前最低卖价（ask price）低于当前出价，按照最低卖价, 最小份额，发生交易
				printf("TRADE %d %d\n", low_quant, lowest_sell.price);
			}else{
				// 对于当前卖订单，若当前最高买价（bid price）高于当前价格，则发生交易。
				printf("TRADE %d %d\n", low_quant, highest_buy.price);
			}
			update_cnt(lowest_sell.c, lowest_sell.price, low_quant * -1);
			update_cnt(highest_buy.c, highest_buy.price, low_quant * -1);								
			if(lowest_sell.quant == 0) sell_queue.pop();
			if(highest_buy.quant == 0) buy_queue.pop();
		}
	}
}

// 更新交易BOOK
void update_cnt(char ins, int price, int quant){
    map<int, int>::iterator iter;
    if(ins == 'B'){
        iter = buy_cnt.find(price);
        if( iter != buy_cnt.end()){
            int tmp_q = buy_cnt[price];
            buy_cnt[price] = quant + tmp_q;
        }else{
            buy_cnt[price] = quant;
        }
    } else { //(ins == 'S')
        iter = sell_cnt.find(price);
        if( iter != sell_cnt.end()){
            int tmp_q = sell_cnt[price];
            sell_cnt[price] = quant + tmp_q;
        } else {
            sell_cnt[price] = quant;
        }
    } 
}

// 打印交易BOOK
void print_quote(){
/*
    CMD b_order = buy_queue.top();
    CMD s_order = sell_queue.top();
    map<int, int>::iterator iter;
    printf("QUOTE ");

    iter = buy_cnt.find(b_order.price);
    if(iter != buy_cnt.end()){
        printf("%d %d", b_order.price, b_order.quant);
    } else {
        printf("0 0");
    }
    printf(" - ");

    iter = sell_cnt.find(s_order.price);
    if(iter != sell_cnt.end()){
        printf("%d %d", s_order.price, s_order.quant);
    }else {
        printf("0 99999");
    }
    printf("\n");
*/
}


