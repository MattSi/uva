#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct ok
{
    map<int,int> record; //记录那句话，有几个重复的
};
ok a[10001];
int main()
{
    int i,j,k,l,n,m,num;
    string hold,temp;
    map<string,int> key;
    map<string,int> ignore;
    vector<string> lines;
    while(cin>>hold&&hold!="::")  ignore[hold]++;
    int count=0,label=0;                           //句子标号，关键词所映射的标号
    getchar();
    while(getline(cin,hold))
    {
        for(i=0;i<hold.size();i++) hold[i]=tolower(hold[i]);
        lines.push_back(hold);
        istringstream in(hold);
        while(in>>temp)
        {
            if(ignore.find(temp)==ignore.end())
            {
                if(key.find(temp)==key.end())     key[temp]=label++;
                a[key[temp]].record[count]++;
            }
        }
        count++;
    }
    map<string,int>::iterator ii;
    map<int,int>::iterator jj;
    for(ii=key.begin();ii!=key.end();ii++)
    {
        for(jj=a[ii->second].record.begin();jj!=a[ii->second].record.end();jj++)
        {
            for(i=1;i<=jj->second;i++)
            {
                hold=lines[jj->first];
                int exist=0;
                istringstream in(hold);
                string ans="";
                while(in>>temp)
                {
                    if(temp==ii->first)
                    {
                        exist++;
                        if(exist==i) for(k=0;k<temp.size();k++) temp[k]=toupper(temp[k]);
                    }
                    if(ans!="") ans+=" ";
                    ans+=temp;
                }
                cout<<ans<<"\n";
            }
        }
    }
}