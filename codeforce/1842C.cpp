#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int a[N],dp[N],mx[N],f[N]; 
void solve()
{ 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(f[a[i]]==0)f[a[i]]=i;
    }
    dp[1]=0;
    for(int i=1;i<=n;i++)mx[a[i]]=f[a[i]];
    for(int i=2;i<=n;i++)
    {   
        if(f[a[i]]==i)dp[i]=dp[i-1];
        else dp[i]=max(dp[i-1],dp[mx[a[i]]-1]+i-mx[a[i]]+1);
        if(i-1-dp[i-1]<mx[a[i]]-dp[mx[a[i]]-1]-1)
        {
            mx[a[i]]=i;
        }
    }
    cout<<dp[n]<<"\n";
    //clear 
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        f[a[i]]=0;
    }
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