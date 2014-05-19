#include <stdio.h>
#include <stdlib.h>
#define N 8

int q[N];
int check(int k)
{
    int i;
    for(i = 0; i < k; i++)
    {
        if(     (q[i] == q[k] ) ||
                (abs(k - i) == abs(q[k] - q[i]))
           )
            return 0;
    }
    return 1;
}

void queens()
{
    int k = 0; // 当前列坐标
    int num = 0;
    q[0] = -1;
    while( k >= 0){
        q[k] += 1;
        while((q[k] < N) && !check(k))
            q[k] += 1;
        if(q[k] < N){
            if(k == (N-1)){// 得到一个排列 Print it.
                /*
                printf("%5d:", ++num);
                for(int i=0; i<=k; i++)
                    printf("%5d", q[i]);
                printf("\n");
                */
                ++num;
            }
            else
                q[++k] = -1;
        }
        else
            k--;
    }
    printf( "%d\n", num);
}

void usage(){
    printf("add argument N\n");
}

int main(int argc, char* argv[])
{
    queens();
    return 0;
}
