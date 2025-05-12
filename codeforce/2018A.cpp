#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n,0);
    ll mx = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i], mx = max(mx,arr[i]);
    ll sm = accumulate(arr.begin(),arr.end(),0LL);
    for(int i = n; i >= 1; i--){
        ll need = mx*i;
        need = max(need, sm+(i-sm%i)%i);
        cout << mx*i << " " << sm+sm%i << "\n";
        if(need-sm <= k){
            cout << i << "\n";
            return;
        }
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}