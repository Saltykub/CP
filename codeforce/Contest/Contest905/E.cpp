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
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=0;
    ll dummy=0;
    ll now=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
        ll cal=ceil(log2(ceil(1.0*arr[i-1]/arr[i])));
        ans+=cal+dummy;
        dummy+=cal;
        now=arr[i]*pow(2,dummy);
        }
        else if(arr[i]==arr[i-1]&&arr[i]<now)ans+=dummy;
        else if(arr[i]<now){
            ll cal=floor(log2(1.0*arr[i]/arr[i-1]));
            if(arr[i]/arr[i-1]==1)cal=0;
            ans+=dummy-cal;
            dummy-=cal;
        }else{
            dummy=0;
        }
        cout<<now<<" "<<dummy<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}
int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}