#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   int n,k,a,b;
   cin>>n>>k>>a>>b;
   ll atom = LLONG_MAX;
   ll mtob = LLONG_MAX;
   //cout<<atom;
   pii point[n+5];
   for(int i=1;i<=n;i++)cin>>point[i].st>>point[i].nd;
   for(int i=1;i<=k;i++)
   {
      atom= min(atom,abs(point[a].st-point[i].st)+abs(point[a].nd-point[i].nd));
      mtob= min(mtob,abs(point[b].st-point[i].st)+abs(point[b].nd-point[i].nd));
   }
   ll mxdis=0;
   if(atom!=LLONG_MAX)mxdis=atom+mtob;
   else mxdis=LLONG_MAX;
   cout<<min(abs(point[a].st-point[b].st)+abs(point[a].nd-point[b].nd),mxdis)<<"\n";
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