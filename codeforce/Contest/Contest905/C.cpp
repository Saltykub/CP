#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=1000;
    int mod2=0;
    for(int i=0;i<n;i++)
    {
       int x;
       cin>>x;
       if(x%2==0)mod2++;
       ans=min(ans,k-x%k);
       if(x%k==0)ans=0;
    }
    if(k==4)
    {
      if(mod2>=2)ans=0;
      else if(mod2==1)ans=min(ans,1);
      else ans=min(ans,2);
    }
    cout<<ans<<"\n";
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