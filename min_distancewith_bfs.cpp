/*
https://codeforces.com/contest/769/problem/C

it says jekhan theke gecho sekhane aste hbe lexicographily


*/
#include<bits/stdc++.h>
using namespace std;
char arr[2000][2000];
vector<char>ans;
long long n,m,k;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
long long level[2000][2000];
bool is_valid(int src1,int src2)
{
    if(src1>=1 && src1<=n && src2>=1 && src2<=m && arr[src1][src2]!='*')
    {
        return true;
    }
    return false;
}
void bfs(int src1,int src2)
{
    queue<pair<long long,long long>>q;
    q.push({src1,src2});
    int x=src1,y=src2;
    level[x][y]=0;
    while(!q.empty())
    {
        long long x=q.front().first;
        long long y=q.front().second;
        q.pop();
        for(int k=0;k<=3;k++)
        {
             int x1=x+dx[k];
             int y1=y+dy[k];
             if(is_valid(x1,y1) && level[x][y]+1<level[x1][y1])
             {
                 level[x1][y1]=level[x][y]+1;
                 q.push({x1,y1});
             }
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
         cin>>n>>m>>k;
         long long src1,src2;
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             {
                 level[i][j]=INT_MAX;
                 cin>>arr[i][j];
                 if(arr[i][j]=='X')
                 {
                     src1=i;
                     src2=j;
                 }
             }
         }
         if(k%2)
         {
             cout<<"IMPOSSIBLE"<<endl;
             continue;
         }
         bfs(src1,src2);
         long long x=src1,y=src2;
       ///  cout<<"sajib"<<endl;
         int f=0;
         while(k--)
         {

             if(is_valid(x+1,y) && level[x+1][y]<=k)
             {
                 cout<<'D';
                 x++;

             }
             else if(is_valid(x,y-1) && level[x][y-1]<=k)
             {
                 y--;
                 cout<<"L";

             }
             else if(is_valid(x,y+1) && level[x][y+1]<=k)
             {
                 y++;
                 cout<<"R";
             }
             else if(is_valid(x-1,y) && level[x-1][y]<=k)
             {
                 x--;
                 cout<<"U";
             }
             else
             {
                 f=1;
                 break;
             }
         }
         if(f)
         {
             cout<<"IMPOSSIBLE"<<endl;
         }
         cout<<endl;


    }
    return 0;
}

