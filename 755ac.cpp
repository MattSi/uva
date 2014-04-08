#include<string>
#include<stdlib.h>
#include<cstdio>
#include<stdio.h>
#include<string.h>
typedef struct node
{
    char num[35];
    int count;
}tele;
tele tel[100005];
int cmp(const void *a,const void *b)
{
    return strcmp((*(struct node*)a).num,(*(struct node*)b).num);
}
void transfrom(char str[],char num[])
{
    int i,j;
    int len;
    len = strlen(str);
    for(i = 0;i < len;i++)
    if(str[i] >= 'a'&&str[i] <= 'z')
    str[i] -= 32;

    for(i =0,j = 0; str[i] != 0;i++)
    {
        if(isdigit(str[i]))
        num[j++] = str[i];
        else if(isalpha(str[i]))
        {
            if(str[i]<='C' && str[i]>= 'A')
            num[j++] = '2';
            if(str[i] <= 'F' && str[i]>= 'D')
            num[j++] = '3';
            if(str[i] <= 'I' && str[i] >= 'G')
            num[j++] = '4';
            if(str[i] <= 'L' && str[i] >= 'J')
            num[j++] = '5';
            if(str[i] <= 'O' && str[i] >= 'M')
            num[j++] = '6';
            if(str[i] == 'S' ||  str[i] == 'P' ||str[i] == 'R')
            num[j++] = '7';
            if(str[i] == 'V' ||str[i] == 'T' ||str[i] == 'U' )
            num[j++] = '8';
            if(str[i] == 'W' ||str[i] == 'X' ||str[i] == 'Y' )
            num[j++] = '9';
        }
        if(j == 3)
        num[j++] = '-';
    }
    num[j] = '\0';
}
int main()
{
    int t,n,i,j,count;
    char str[100],num[15];
#ifndef ONLINE_JUDGE
    freopen("./tests/755.in", "r", stdin);
    freopen("./tests/755ac.out", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0;i < n;i++)
        {
            scanf("%s",str);
            transfrom(str,num);
            strcpy(tel[i].num,num);
            tel[i].count = 1;
        }
        qsort(tel,n,sizeof(tel[0]),cmp);
        int leap;
        leap = 1;
        for(i = 0;i < n-1;i++)
        {
            int count = 1;
            if(strcmp(tel[i].num,tel[i+1].num)==0 && i< n)
            {
                while(strcmp(tel[i].num,tel[i+1].num)==0&&i<n) count++,i++;
                printf("%s %d\n",tel[i].num,count);
                leap = 0;
            }

        }
        if(leap)
        puts("No duplicates.");
        if(t)
        puts("");
    }
    return 0;
}
