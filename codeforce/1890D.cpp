#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
   ll n,c;
   cin>>n>>c;
   vector<pii> v;
   ll sum=0;
   for(int i=1;i<=n;i++){
      ll x;
      cin>>x;
      if(i==1)sum=x;
      if(i!=1){v.pb({i*c-x,x});}
   }
   bool can=true;
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++){
    if(sum>=v[i].st){
        sum+=v[i].nd;
    }
    else {
        can=false;
        break;
    }
   }
   if(can)cout<<"Yes";
   else cout<<"No";
   cout<<"\n";
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