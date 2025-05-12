#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n,greater<ll>());
    cout << arr[0]*arr[1];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}