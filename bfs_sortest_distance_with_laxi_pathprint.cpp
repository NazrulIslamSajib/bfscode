/*
https://www.spoj.com/problems/DIGOKEYS/

lexicographically sortest distance ber kora . it was good problem

*/
#include<bits/stdc++.h>
using namespace std;
vector<long long>arr[100010];
long long n;
long long dis[100010];
long long path[100010];
void bfs()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }
    queue<long long>q;
    q.push(1);
    dis[1]=0;
    path[1]=-1;
    while(!q.empty())
    {
        long long u=q.front();
        q.pop();
        for(auto v:arr[u])
        {

            if(dis[u]+1<dis[v])
            {
                path[v]=u;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {

       cin>>n;
       for(int i=1;i<=n;i++)
       {
           arr[i].clear();
       }
       for(int i=1;i<=n-1;i++)
       {
           long long x;
           cin>>x;
           for(int j=1;j<=x;j++)
           {
               int u;
               cin>>u;
               arr[i].push_back(u);
           }
           sort(arr[i].begin(),arr[i].end());
       }
       bfs();
       if(dis[n]!=INT_MAX)
       {

           cout<<dis[n]<<endl;
           vector<long long>ans;
           while(path[n]!=-1)
           {
               ans.push_back(path[n]);
               n=path[n];
           }
           reverse(ans.begin(),ans.end());
           for(auto x:ans)
           {
               cout<<x<<" ";
           }
           cout<<endl;

       }
       else
       {
           cout<<-1<<endl;
       }
       cout<<endl;

    }
    return 0;
}


