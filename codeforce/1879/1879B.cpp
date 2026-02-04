#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n;
    cin>>n;
    ll a[n+2],b[n+2];
    ll sma=0,smb=0,mna=LLONG_MAX,mnb=LLONG_MAX;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)
    {
        sma+=a[i];
        smb+=b[i];
        mna=min(a[i],mna);
        mnb=min(b[i],mnb);
    }
    cout<<min(sma+mnb*n,smb+mna*n)<<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}