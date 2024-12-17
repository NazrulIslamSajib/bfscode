/* 

https://vjudge.net/problem/UVA-429 
1 different thakbe input problem uva
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
        vector<string>v;
        while(1)
        {
            string s;
            cin>>s;
            if(s!="*")
            {
                v.push_back(s);
            }
            else
            {
                break;
            }
        }
        cin.ignore();
        string line;
        while(getline(cin,line) && line!="")
        {
            stringstream ss(line);
            string s,t;
            ss>>s>>t;
            queue<string>q;
            q.push(s);
            unordered_map<string,long long>dis;
            for(auto x:v)
            {
                dis[x]=INT_MAX;
            }
            dis[s]=0;
            unordered_map<string,bool>mp;
            int f=0;
            while(!q.empty())
            {
                 string u=q.front();
                 q.pop();
                 for(auto x:v)
                 {
                     long long diff=0;
                     if(mp[x]==false && x.size()==u.size())
                     {
                          for(int j=0;j<x.size();j++)
                          {
                            if(x[j]!=u[j])
                            {
                              diff++;
                            }
                          }
                     }
                     if(diff==1)
                     {
                         dis[x]=dis[u]+1;
                         mp[x]=true;
                         if(x==t)
                         {
                             f=1;
                             break;
                         }
                         q.push(x);

                     }

                 }
                 if(f)
                 {
                     break;
                 }
            }
            cout<<s<<" "<<t<<" "<<dis[t]<<endl;

        }
        if(tt)
        {
            cout<<endl;
        }


    }
    return 0;
}
