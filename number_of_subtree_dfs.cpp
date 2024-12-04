////ektar niche arek ta arek ta subtree ber korar niyom koyta ache segula dfs
////https://cses.fi/problemset/task/1674/
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<long long>arr[mx];
bool vis[mx];
long long dp[mx],n;
void dfs(int i)
{

    vis[i]=true;
    long long cnt=0;
    for(auto x:arr[i])
    {
        if(vis[x]==false)
        {
            dfs(x);
            cnt+=1+dp[x];

        }
    }

    dp[i]=cnt;

}
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        long long x;
        cin>>x;
        arr[x].push_back(i);

    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

}
