#include <stdio.h>
#include <string.h>
#define STACK_SIZE 256

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    FILE *fp = freopen("./tests/673.in", "r", stdin);
#endif
    char stack[STACK_SIZE], buffer[STACK_SIZE];
    int sp, num, c, i;
    size_t len;
    
    scanf("%d", &num);getchar();
    while(num-- > 0){
        sp = 0;
        fgets(buffer, STACK_SIZE, stdin);
        
        len = strlen(buffer);
        if( buffer[len-1] == '\n')
            buffer[--len] = '\0';
        
        for(i=0; i<len; i++){
            if(buffer[i] == '[' || buffer[i] == '(')
                stack[sp++] = buffer[i];
            else{
                if(buffer[i] != ')' && buffer[i] != ']')continue;

                if(!sp){sp--;break;}
                sp--;
                if((stack[sp] == buffer[i]-1) || (stack[sp] == buffer[i]-2) ) continue;
                else {sp=-1; break;}
                
            }
        }   
        if(!sp)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
