/*
https://vjudge.net/problem/UVA-439
*/
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,-2,-1,-2,1,2,1,2};
int dy[]={2,1,-2,-1,-2,-1,2,1};
bool is_valid(int i,int j)
{
    if(i>=1 && i<=8 && j>=1 && j<=8)
    {
        return true;
    }
    return false;
}
int main()
{

    map<char,long long>mp;
    mp['a']=1;
    mp['b']=2;
    mp['c']=3;
    mp['d']=4;
    mp['e']=5;
    mp['f']=6;
    mp['g']=7;
    mp['h']=8;
    string line;
    while(getline(cin,line) && line!="")
    {
        stringstream ss(line);
        string s,t;
        ss>>s>>t;
        int col1=mp[s[0]];
        int row1=s[1]-'0';
        int col2=mp[t[0]];
        int row2=t[1]-'0';
        queue<pair<long long,long long>>q;
        q.push({row1,col1});
        long long level[100][100];
        for(int i=1;i<=90;i++)
        {
            for(int j=1;j<=90;j++)
            {
                level[i][j]=0;
            }
        }
        level[row1][col1]=1;
        while(!q.empty())
        {
            long long i=q.front().first;
            long long j=q.front().second;
            q.pop();
            int f=0;
            for(int k=0;k<=7;k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(is_valid(x,y) && level[x][y]==0)
                {
                    level[x][y]=level[i][j]+1;
                    q.push({x,y});
                }
            }

        }
        cout<<"To get from "<<s<<" to "<<t<<" takes "<<level[row2][col2]-1<<" knight moves."<<endl;

    }




    return 0;
}

