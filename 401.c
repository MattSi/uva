#include <stdio.h>
#include <string.h>
#define ROW 36
#define N 8192
char table[ROW][2] = {
        { '1', '1' },
        { '2', 'S' },
        { '3', 'E' },
        { '5', 'Z' },
        { '8', '8' },
        { 'A', 'A' },
        { 'E', '3' },
        { 'H', 'H' },
        { 'I', 'I' },
        { 'J', 'L' },
        { 'L', 'J' },
        { 'M', 'M' },
        { 'O', 'O' },
        { 'S', '2' },
        { 'T', 'T' },
        { 'U', 'U' },
        { 'V', 'V' },
        { 'W', 'W' },
        { 'X', 'X' },
        { 'Y', 'Y' },
        { 'Z', '5' }
};

char map(char c){
    int i;
    for(i=0; i<ROW; i++){
        if(c == table[i][0])
            return table[i][1];
    }
    return '$' ;
}

int main(int argc, char* argv[])
{
    int i, j, len;
    char sentence[N];
	char mirror[N];
    short bp,bm;
#ifndef ONLINE_JUDGE
    FILE *fp = NULL;
    fp = freopen("./tests/401.in", "r", stdin);
    fp = freopen("./tests/401.out", "w", stdout);
#endif
    while(scanf("%s" , sentence)!=EOF){
        bp = 1, bm = 1;
        len = strlen(sentence);
        for(i = 0, j = len-1; i<=j; i++, j--){
            if(sentence[i] != sentence[j]) bp = 0;
            if(map(sentence[i]) != sentence[j])bm = 0;
            if(!(bm||bp))break ; /*nether p or m */
        }
        if(!(bm||bp))printf("%s -- is not a palindrome.\n\n" , sentence);
        else if (bp && !bm) printf("%s -- is a regular palindrome.\n\n", sentence);
        else if (bm && !bp) printf("%s -- is a mirrored string.\n\n", sentence);
        else printf("%s -- is a mirrored palindrome.\n\n" , sentence);
    }
    return 0;
}

