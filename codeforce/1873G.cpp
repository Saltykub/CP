#include<bits/stdc++.h>
#define ll int
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    string s; 
    cin>>s;
    int a=0;
    int mn=INT_MAX;
    int now=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B')
        {
            mn=min(mn,now);
            now=0;
        }
        else 
        {
            now++;
            a++; 
        }
    }
    mn=min(mn,now);
    cout<<a-mn<<"\n";
    
}
signed main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}