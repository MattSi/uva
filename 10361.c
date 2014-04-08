#include <stdio.h>
#include <string.h>

#define N 120
int strs[5]={0};
void analyse(char line[N]){
    int i=0, i1=0;
    while(line[i] != '\0'){
        if(line[i] == '<' || line[i] == '>'){strs[++i1]=i+1; line[i]= '\0';}
        i++;
    }
}
void display1(char line[N]){
    char *p = line; 
    int i = 0;
    while(i<5)printf("%s", p+strs[i++]);
    printf("\n");
}
void display2(char line1[N], char line2[N]){
    char *p = strstr(line2, "...");
    *p = '\0';
    printf("%s", line2);
    p = line1;
    printf("%s%s%s%s\n", p+strs[3],p+strs[2],p+strs[1],p+strs[4]);
}
int main(int argc, char* argv[]){
    int num, len, nouse;
    char line1[N], line2[N], *nousec;
#ifndef ONLINE_JUDGE
    FILE* fp=NULL;
    fp = freopen("./tests/10361.in", "r", stdin);
    fp = freopen("./tests/10361.out", "w", stdout);
#endif
    nouse = scanf("%d\n", &num);
    while(num-- > 0){
        nousec = fgets(line1, N, stdin);
        len = strlen(line1);
        if(line1[len-1] == '\n')line1[len-1]='\0';
        nousec = fgets(line2, N, stdin);
        len = strlen(line2);
        if(line2[len-1] == '\n')line2[len-1]='\0';
        analyse(line1);
        display1(line1);
        display2(line1, line2);
    }
    return 0;
}

