#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const ll R=1e12;
const int N = 2e5;
ll h[N];
void solve()
{ 
    ll n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>h[i];
    ll l=1,r=R;
    while(l<r)
    {
        ll mid=(l+r+1)/2;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(h[i]<mid)ans+=mid-h[i];
        }
        //cout<<ans<<" ";
        if(ans>x)r=mid-1;
        else l=mid;
    }
    cout<<r<<"\n";
    
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