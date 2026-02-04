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
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    ll sm = 0;
    for(int i=1;i<n;i++){
        sm += (arr[i]-arr[i-1]);
    }
    cout<<sm<<"\n";
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