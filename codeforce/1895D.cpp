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
    int sum[n];
    for(int i=0;i<n-1;i++)cin>>arr[i];
    sum[0]=arr[0];
    for(int i=1;i<n-1;i++){sum[i]=sum[i-1]^arr[i];}
    int ans[32];
    for(int i=0;i<=30;i++){
        int one = 0;
    for(int j=0;j<n-1;j++){
        if(sum[j]&(1<<i))one ++;
    }
    if(one>n-1-one)ans[i]=1;
    else ans[i]=0;
    }
    ll start=0;
    for(int i=0;i<=30;i++)if(ans[i])start+=pow(2,i);
    cout<<start<<" ";
    for(int i=0;i<n-1;i++){
        start^=arr[i];
        cout<<start<<" ";
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