#include<bits/stdc++.h>
#define int long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int h[n];
    int ans=0;
    int now=0;
    int sum=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cin>>h[i];
    now=0;
    sum=arr[0];
    for(int i=1;i<n;i++)
    {   
        if(h[i-1]%h[i]==0)
        {   
            sum+=arr[i];
            while(sum>k)
            {
                sum-=arr[now];
                now++;
            }
            //cout<<now<<" ";
            ans=max(ans,i-now+1);
        }
        else 
        {
            now=i;
            sum=arr[i];
        }
    }
    int one=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)ans=max(ans,one);
    }
    cout<<ans<<"\n";
}
signed main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}