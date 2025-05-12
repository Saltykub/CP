#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 998244353;
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    vector<ll> arr(n+1,0);
    ll ans = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 0; i < 30; i++){
        vector<ll> pref = {1,0};
        vector<ll> sm(2);
        ll cur = 0, s = 0;
        for(int j = 1; j <= n; j++){
            s^=(arr[j]>>i)&1;
            ll smr = j*pref[s^1]%MOD;
            smr %= MOD;
            cur += smr;
            cur%=MOD;
            cur-=sm[s^1];
            cur%=MOD;
            pref[s]++;
            sm[s] += j;
            sm[s]%=MOD;
        }
        ans += (cur)*(1 << i) % MOD;
        ans%=MOD;
    }
    if(ans < 0) ans+=MOD;
    ans%=MOD;
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}