#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;

void solve()
{ 
    string s;
    cin>>s;
    int sz=s.size();
    int ct=0;
    s="0"+s;
    for(int i=1;i<=sz;i++)
    {   
        if(s[i]=='_'&&s[i-1]=='0')ct++;
        if(s[i]=='_'&&s[i+1]!='^')ct++;
    }
    if(sz==1&&s[1]=='^')ct++;
    cout<<ct<<"\n";

}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}