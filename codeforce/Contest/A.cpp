#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
   int a,b,n;
   cin>>a>>b>>n;
   int bomb[n];
   for(int i=0;i<n;i++)cin>>bomb[i];
   ll ans=0;
   ans+=b-1;
   for(int i=0;i<n;i++)ans+=min(bomb[i],a-1);
   cout<<ans+1<<"\n";

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