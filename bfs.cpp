#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>v,int n,int source)
{
    //vector<vector<int>>v(n+1);
    queue<int>q;
    vector<int>leve(n+1,-1);
    q.push(source);
    leve[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x:v[u])
        {
            if(leve[x]==-1)
            {
                leve[x]=leve[u]+1;
                q.push(x);

            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        cout<<leve[j]<<endl;
    }

}
int main()
{
    int n,m,i;
    cout<<"Enter node"<<endl;
    cin>>n;
    vector<vector<int>>v(n+1);
    cout<<"Enter edge"<<endl;
    cin>>m;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(v,n,6);
    return 0;
}
