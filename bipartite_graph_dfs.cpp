#include<bits/stdc++.h>
using namespace std;
bool vis[200010];
vector<long long>arr[200010];
long long dp[200020];
int f=0;
void dfs(int i,int color)
{
    if(vis[i]==true)
    {
        return;
    }
    vis[i]=true;
    for(auto x:arr[i])
    {
        if(vis[x]==false)
        {
            dp[x]=color^1;
            dfs(x,dp[x]);
        }
        else if(dp[i]==dp[x])
        {
            f=1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       long long n,m;
       cin>>n>>m;
       for(int i=1;i<=m;i++)
       {
           long long u,v;
           cin>>u>>v;
           arr[u].push_back(v);
           arr[v].push_back(u);
       }
       for(int i=1;i<=n;i++)
       {
           if(vis[i]==false)
           {
               dp[i]=0;
               dfs(i,0);
           }
       }
       if(f)
       {
           cout<<"IMPOSSIBLE"<<endl;
           continue;
       }
       for(int i=1;i<=n;i++)
       {
           if(dp[i]==0)
           {
              cout<<1<<" ";
           }
           else
           {
               cout<<2<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}


