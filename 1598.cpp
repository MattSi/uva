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
#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>


using namespace std;

struct CMD{
    int id;
    int quant;
    int price;
    bool valid;
    CMD(int _id, int _quant, int _price, bool _valid):
        id(_id), quant(_quant), price(_price), valid(_valid){}
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

void find_trade(char trigger){
    if(trigger == 'B'){
    
    }else{
    }
}

void print_quote(){
}

int n;
priority_queue<CMD, vector<CMD>, cmp_less> buy_queue;
priority_queue<CMD, vector<CMD>, cmp_more> sell_queue;
map<int, CMD*> id_map;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    FILE *fp = freopen("./tests/1598.in", "r", stdin);
#endif
    while(scanf("%d\n", &n)==1){
        while(!buy_queue.empty())buy_queue.pop();
        while(!buy_queue.empty())sell_queue.pop();
        id_map.clear();

        char inst[8];
        int quant, price;
        for(int i=1; i<=n; i++){
            if(scanf("%s %d %d\n", inst, &quant, &price) == 3){
                CMD *c = new CMD(i, quant, price, true);
                id_map.insert(pair<int, CMD*>(i, c));
                switch(inst[0]){
                    case 'b':
                    case 'B':
                        buy_queue.push(*c);
                        break;
                    case 's':
                    case 'S':
                        sell_queue.push(*c);
                        break;
                    break:
                        break;
                }
            }else {
                CMD* cmd = id_map.at(quant); //quant在这里等于要取消的交易id
                cmd->valid = false;
            }
        }
        printf("======End\n");
    }
    /*
    CMD *c = new CMD(1,100, 35, true);
    buy_queue.push(*c);
    id_map.insert(pair<int, CMD*>(1, c));
    buy_queue.push(new CMD(1, 100, 35, true));
    buy_queue.push(new CMD(2, 100, 34, true));
    buy_queue.push(new CMD(3, 100, 32, true));
    buy_queue.push(new CMD(4, 100, 36, true));
    buy_queue.push(new CMD(5, 100, 35, true));
*/
    /*
    while (!buy_queue.empty()){
        printf("ID: %5d, PRICE: %5d\n", buy_queue.top().id, buy_queue.top().price);
        buy_queue.pop();
    }
*/
    //CMD* cmd = id_map.at(1);
    //cout<<id_map.at(1)->price<<endl;
    return 0;
}
