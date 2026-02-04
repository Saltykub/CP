#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    ll n;
    cin>>n;
    ll l=1,r=10000000000;
    while(l<r)
    {
        ll mid=(l+r+1)/2;
        ll cal=mid*(mid-1);
        cal/=2;
        if(cal>n)r=mid-1;
        else l=mid;
    }
    cout<<l+(n-(l*(l-1)/2))<<"\n";
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