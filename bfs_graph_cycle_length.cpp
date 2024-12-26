////https://cses.fi/problemset/task/1707
#include<bits/stdc++.h>
using namespace std;
vector<long long>arr[3000];
vector<pair<long long,long long>>v1;
long long dis[10000];
long long vis[10000];
long long bfs(int u,int v)
{
    long long ans=INT_MAX;
    queue<long long>q;
    q.push(u);
    dis[u]=0;
    vis[u]=1;
    while(!q.empty())
    {

    int x=q.front();
    q.pop();
    for(auto y:arr[x])
    {
        if(u==x && y==v)
        {
            continue;
        }
        if(y==v)
        {
            dis[y]=dis[x]+1;
            ans=min(ans,dis[y]+1);
        }
        else if(vis[y]==0)
        {
           q.push(y);
           dis[y]=dis[x]+1;
           vis[y]=1;
        }
    }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ////cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);
            v1.push_back({u,v});
        }
        long long ans1=INT_MAX;
        for(int i=0;i<m;i++)
        {
             int u=v1[i].first;
             int v=v1[i].second;
             memset(dis,0,sizeof(dis));
             memset(vis,0,sizeof(vis));
             long long cnt=bfs(u,v);
             ans1=min(ans1,cnt);
        }
        if(ans1==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<ans1<<endl;
        }
    }
    return 0;
}


