#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int now=n;
    for(int i=1;i<=min(n,k);i++){
        //cout<<now<<" ";
        if(arr[now]>n){
            cout<<"No"<<"\n";
            //cout<<arr[now]<<" ";
            return;
        }
        else{
           if(arr[now]>=now){
            now=n+(now-arr[now]);
           }
           else now=now-arr[now];
        }
    }
    cout<<"Yes"<<"\n";
    
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