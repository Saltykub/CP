#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int arr[N];
void solve()
{
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=2;i<=n;i++)arr[i]^=arr[i-1];
  while(q--){
    int l,r;
    cin>>l>>r;
    int al=arr[l-1],ar=arr[r];
    cout<<(al^ar)<<"\n";
    }
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}