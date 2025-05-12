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
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ans+=__gcd(arr[i],arr[i+1])*(n-i-2);
    }
    cout<<ans<<"\n";
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