#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int regi[10];
int memo[1000];

int cal(int num){
    int i;
    int pc = 0, count = 0, cmd;
    int op, d, s; /* cmd = op+d+s*/
    
    while(1){
        cmd = memo[pc];
        count++;
        if(cmd == 100)
            break;
        op = cmd / 100;
        s  = cmd % 10;
        d  = (cmd - 100*op) / 10;
        switch(op){
            case 2:
                regi[d] = s;
                pc++;
                break;
            case 3:
                regi[d] = (regi[d] + s) % 1000;
                pc++;
                break;
            case 4:
                regi[d] = (regi[d] * s) % 1000;
                pc++;
                break;
            case 5:
                regi[d] = regi[s];
                pc++;
                break;
            case 6:
                regi[d] = (regi[s] + regi[d]) % 1000;
                pc++;
                break;
            case 7:
                regi[d] = (regi[s] * regi[d]) % 1000;
                pc++;
                break;
            case 8:
                regi[d] = memo[regi[s]];
                pc++;
                break;
            case 9:
                memo[regi[s]] = regi[d];
                pc++;
                break;
            case 0:
                if(regi[s])
                    pc = memo[regi[d]];
                else
                    pc++;
                break;
            default:
                break;
        }
    }


    return count;
}
int main(int argc, char* argv[]){
    int times;
    int pc;
    char cmd[10];
    size_t len;
#ifndef ONLINE_JUDGE
    freopen("./tests/10033.in", "r", stdin);
#endif
    scanf("%d\n", &times);
    while(times--){
        memset(regi, 0, sizeof(regi));
        memset(memo, 0, sizeof(memo));
        pc = 0;
        while(fgets(cmd, 10, stdin)){
            len = strlen(cmd);
            if(cmd[len-1] == '\n'){
                cmd[len-1] = '\0';
                len--;
            }
            if(!len){
                cal(pc);
                pc = 0;
                break;
            }
            else{
                memo[pc++] = atoi(cmd);
            }
        }
        if(pc){
            cal(pc);
            pc = 0;
        }
    }
    return 0;
}
