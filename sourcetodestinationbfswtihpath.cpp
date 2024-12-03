//https://cses.fi/problemset/task/1193
 //ekta soruce deoya thakbe and ekta destination deoya thakbe sortest path konta jeta a theke
 /// b te jaite parbo seta print korte heb eta bfs diye korte parbo path lagbe .


#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
char arr[1010][1010];
long long n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char path[1010][1010];
bool valid(int x,int y)
{
    if(vis[x][y]==false && x>=1 && x<=n && y<=m && y>=1 && (arr[x][y]=='.' || arr[x][y]=='B'))
    {
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ////cin>>tt;
    while(tt--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
            }
        }
        pair<int,int>src1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i][j]=='A')
                {
                    src1={i,j};
                }
            }
        }
        queue<pair<int,int>>q;
        q.push(src1);
        int f=0;
        vector<char>ans;
        vis[src1.first][src1.second]=true;
        while(!q.empty())
        {
            long long x=q.front().first;
            long long y=q.front().second;
            q.pop();
            if(arr[x][y]=='B')
            {
                f=1;
                while(1)
                {
                    ans.push_back(path[x][y]);
                    if(ans.back()=='U')
                    {
                        x++;
                    }
                    if(ans.back()=='L')
                    {
                        y++;
                    }
                    if(ans.back()=='R')
                    {
                        y--;
                    }
                    if(ans.back()=='D')
                    {
                        x--;
                    }
                    if(arr[x][y]=='A')
                    {
                        break;
                    }

                }
                break;
            }
            for(int i=0;i<=3;i++)
            {
                long long x1=x+dx[i];
                long long y1=y+dy[i];
                if(x1==x && y1==y-1 && valid(x1,y1))
                {
                    q.push({x1,y1});
                    path[x1][y1]='L';
                    vis[x1][y1]=true;
                }
                if(x1==x && y1==y+1 && valid(x1,y1))
                {
                    q.push({x1,y1});
                    path[x1][y1]='R';
                    vis[x1][y1]=true;
                }
                if(x1==x-1 && y1==y && valid(x1,y1))
                {
                    q.push({x1,y1});
                    path[x1][y1]='U';
                    vis[x1][y1]=true;
                }
                if(x1==x+1 && y1==y && valid(x1,y1))
                {
                    q.push({x1,y1});
                    path[x1][y1]='D';
                    vis[x1][y1]=true;
                }
            }
        }
        if(f)
        {
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            for(int i=ans.size()-1;i>=0;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

