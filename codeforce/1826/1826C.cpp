#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n<=m&&n!=1)cout<<"No";
    else if(n==1)cout<<"yes";
    else if(n%m==0||n%2==0)cout<<"No";
    else cout<<"yes";
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
