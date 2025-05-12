#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
map<ll,int>mp;
void solve()
{
   ll n,m;
   cin>>n>>m;
   int gcdd=__gcd(m,n);
   n/=gcdd;
   m/=gcdd;
   ll ans=0;
   if(n%m==0){cout<<0<<"\n";return;}
   if(mp[m]==0){cout<<-1<<"\n";return;}
   if(n>m)n%=m;
   int now=n;
   while(true)
   {
      if(now<m)
      {
        ans+=now;
        now*=2;
      }
      else if(now>m)now-=m;
      else if(now==m)break;
   }
   cout<<ans*gcdd<<"\n";

}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    for(int i=1;i<=30;i++)mp[pow(2,i)]=1;
    while(t--)
    {
        solve();
    }
}