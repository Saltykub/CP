#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    string a,b;
    cin>>a>>b;
    bool can=false;
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]==b[i]&&a[i]=='0'&&a[i+1]==b[i+1]&&a[i+1]=='1')
        {
            can=true;
            break;
        }
    }
    if(can)cout<<"YES";
    else cout<<"NO";
    cout<<"\n";
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