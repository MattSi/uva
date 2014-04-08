#include <string.h>  
#include <stdio.h>  
int main()  
{  
#ifndef ONLINE_JUDGE
    freopen("./tests/10152.in", "r", stdin);
    freopen("./tests/10152.acout", "w", stdout);
#endif
    int k,n,c[205],i,j;  
    char a[205][100],b[205][100];  
    scanf("%d",&k);  
    while(k--)  
    {  
        scanf("%d",&n);  
        getchar();  
        for(i=0;i<n;i++)  
            gets(a[i]);  
        for(j=0;j<n;j++)  
            gets(b[j]);  
        for(i=0;i<n;i++)  
               for(j=0;j<n;j++)  
                if(!strcmp(b[j],a[i]))  
                {  
                    c[j]=i;  
                    break;  
                }  
        for(i=n-1;i>=0;i--)  
            if(c[i]<c[i-1])break;  
        for(i--;i>=0;i--)  
            puts(b[i]);  
        printf("\n");  
    }  
   return 0;  
}  

