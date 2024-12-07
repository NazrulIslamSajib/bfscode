/*https://codeforces.com/contest/802/problem/J
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>arr[110];
bool vis[1010];
long long dp[1010],max1=0;
void dfs(int i)
{
    if(vis[i]==true)
    {
        return;
    }
    vis[i]=true;
    long long cnt=0;
    for(auto x:arr[i])
    {
        if(vis[x.first]==false)
        {
           dfs(x.first);
           dp[i]=max(dp[i],x.second+dp[x.first]);
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
  ///  cin>>tt;
    while(tt--)
    {
        long long n;
        cin>>n;
        for(int i=1;i<=n-1;i++)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            arr[u].push_back({v,w});
            arr[v].push_back({u,w});
        }
        dfs(0);
        cout<<dp[0]<<endl;
    }
    return 0;
}

