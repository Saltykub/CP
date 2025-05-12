#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int n,k,x;
    cin>>n>>k>>x;
    if(n<k||x<k-1)cout<<-1;
    else 
    {
        int ans=k*(k-1)/2;
        if(x!=k)ans+=(n-k)*x;
        else ans+=(n-k)*(k-1);
        cout<<ans;
    }
    cout<<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}