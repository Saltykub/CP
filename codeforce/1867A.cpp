#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
  int n;
  cin>>n;
  pii arr[n];
  int ans[n];
  for(int i=0;i<n;i++)cin>>arr[i].st;
  for(int i=0;i<n;i++)arr[i].nd=i;
  sort(arr,arr+n);
  reverse(arr,arr+n);
  for(int i=0;i<n;i++)
  {
    ans[arr[i].nd]=i+1;
  }
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";
  cout<<"\n";
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