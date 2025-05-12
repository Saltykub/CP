#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
map<int,int> mp;
vector<ll> v;
void solve()
{ 
  int n,c,d;
  cin>>n>>d>>c;
  ll cost=LLONG_MAX;
  ll plus=0;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    if(mp[x]==1)plus+=d;
    else v.pb(x);
    mp[x]=1;
  }
  v.pb(0);
  sort(v.begin(),v.end());
  ll sz=v.size();
  for(int i=1;i<sz;i++)
  {
      cost=min(cost,((v[i]-i)*c+(sz-i-1)*d));
      //cout<<cost<<" ";
  }
  cost=min(cost,(sz-1)*d+c);
  cout<<cost+plus<<"\n";
  v.clear();
  mp.clear();
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