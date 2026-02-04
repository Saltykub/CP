#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n+5],b[m+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(b,b+m,greater<int>());
    int now=0;
    for(int i=0;i<n;i++){
        while(b[now]>=arr[i]&&now<=m-1){
            cout<<b[now]<<" ";
            now++;
        }
        cout<<arr[i]<<" ";
    }
    for(int i=now;i<m;i++)cout<<b[i]<<" ";
    cout<<"\n";
    
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