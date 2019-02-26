#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
pair<int,int> loc[200500];
bool flag[200500];
int n,num;
int abs(int s){
    if(s>0)
        return s;
    return -s;
}
int  main(){
    while(~scanf("%d",&n)){
    for(int i=0;i<n+1;i++)
        flag[i]=false;
    for(int i=0;i<2*n;i++)
    {
        scanf("%d",&num);
        if(!flag[num])
        {
            loc[num].first=i;
            flag[num]=true;
        }else
        {
            loc[num].second=i;
        }
    }
    long long temp1,temp2,ans;
    ans=loc[1].first+loc[1].second;
    for(int i=2;i<=n;i++){
        temp1=abs(loc[i].first-loc[i-1].first)+abs(loc[i].second-loc[i-1].second);
        temp2=abs(loc[i].first-loc[i-1].second)+abs(loc[i].second-loc[i-1].first);
        if(temp1<temp2)
            ans+=temp1;
        else
            ans+=temp2;
    }
    printf("%lld\n",ans);
    }
    return 0;
}
