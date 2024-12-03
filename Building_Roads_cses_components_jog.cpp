///problems says onek gula road thakbe kichu cites er modde jader modde connecions ache
/// amar kaj hocche minimum koyta road connect korle eder sobar maje ekta path thakbe
///https://cses.fi/problemset/task/1666/

#include<bits/stdc++.h>
using namespace std;
bool vis[100010];
vector<int>arr[100010];
int n,m;
void dfs(int i)
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
            dfs(x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            long long x,y;
            cin>>x>>y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        vector<long long>ans;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                ans.push_back(i);
                dfs(i);
            }
        }
        if(ans.size()>=2)
        {
            cout<<ans.size()-1<<endl;
            for(int i=0;i<ans.size()-1;i++)
            {
                cout<<ans[i]<<" "<<ans[i+1]<<endl;
            }
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}


