    #include<iostream>  
    #include<cstdio>  
    using namespace std;  
    struct list  
    {  
        int x;  
        int y;  
    }point[100001];  
    int main()  
    {  
        int n,a,b,num,i;  
        while(scanf("%d",&n)&&n)  
        {  
            for(i=0;i<2*n;i++)  
            {  
                scanf("%d%d",&point[i].x,&point[i].y);  
            }  
            int leap=1;  
            for(a=-500;a<=500;a++)  
            {  
                for(b=-500;b<=500;b++)  
                {  
                    num=0;  
                    if(a==0&&b==0)continue;  
                    for(i=0;i<2*n;i++)  
                    {  
                        if((a*point[i].x+b*point[i].y)>0)num++;  
                        if((a*point[i].x+b*point[i].y)==0)break;  
                    }  
                    if(i==2*n&&num==n)  
                    {  
                        leap=0;  
                        break;  
                    }  
                }  
                if(leap==0)break;  
            }  
            printf("%d %d\n",a,b);  
        }  
        return 0;  
    }  
