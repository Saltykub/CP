#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
unordered_map<string,ll> mp;
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    int diff[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(int i=1;i<n;i++)diff[i-1]=arr[i]-arr[i-1];
    int GCD=diff[0];
    for(int i=1;i<n-1;i++)GCD=__gcd(GCD,diff[i]);
    bool use=false;
    ll ans=0;
    reverse(arr,arr+n);
    //cout<<GCD;
    for(int i=1;i<n;i++){
       // cout<<ans<<" ";
        ans+=(arr[0]-arr[i])/GCD;
        if(!use&&(arr[i-1]-arr[i])/GCD>1){
            use=true;
            ans+=(arr[0]-arr[i-1])/GCD+1;
        }
    }
    if(!use)ans+=(arr[0]-arr[n-1])/GCD+1;
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