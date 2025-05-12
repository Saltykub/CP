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
   int arr[n];
   vector<int>v;
   for(int i=0;i<n;i++)cin>>arr[i];
   v.pb(arr[0]);
   for(int i=1;i<n;i++)
   {
     if(arr[i]<arr[i-1])v.pb(1);
     v.pb(arr[i]);
   }
   cout<<v.size()<<"\n";
   for(auto u:v)cout<<u<<" ";
   cout<<"\n";
   v.clear();
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