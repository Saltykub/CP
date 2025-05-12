#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
const int MOD = 998244353;
void solve (){
    int n;
    cin >> n;
    vector<ll> dpt(n+5,0), dpl(n+5,0);
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(arr[0] == 0) dpt[0] = 1;
    dpl[1] = 1;
    ll prev_val = dpt[0], prev_idx = 1, prev_fix = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i-1]) dpt[arr[i-1]] = 0;
        dpt[arr[i]] += dpl[arr[i]]%MOD;
        dpt[arr[i]] %= MOD;
        if(prev_fix != -1){
            dpl[prev_fix] = 0;
        }
        prev_fix = prev_idx;
        dpl[prev_idx] = prev_val;
        prev_idx = arr[i]+1;
        prev_val = dpt[arr[i]] % MOD;
    }
    ll ans = 0;
    ans += dpt[arr[n-1]];
    for(int i = 1; i <= n; i++) {
        ans+=dpl[i];
        ans%=MOD;
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}