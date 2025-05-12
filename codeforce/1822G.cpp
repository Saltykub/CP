#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
const int mx=1e9;
int arr[N];
map<ll,ll> mp,check;
void solve()
{
   int n;
   cin>>n;
   ll ans=0;
   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
     mp[arr[i]]++;
   }
   sort(arr,arr+n);
   for(int i=0;i<n;i++)
   {
       if(arr[i]!=arr[i-1])
       {
          for(int l=2;l<=1000;l++)
          {
            ll j,k;
            j=arr[i]*l;
            k=arr[i]*l*l;
            //cout<<arr[i]<<" "<<j<<" "<<k<<"\n";
            if(k>mx)break;
            if(mp[j]==0||mp[k]==0)continue;
            ans+=mp[arr[i]]*mp[j]*mp[k];
          }
          if(mp[arr[i]]>=3)
          {
            ans+=mp[arr[i]]*(mp[arr[i]]-1)*(mp[arr[i]]-2);
          }
       }  
   }
   cout<<ans<<"\n";
   mp.clear();
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