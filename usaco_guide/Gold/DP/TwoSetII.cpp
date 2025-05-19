#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
ll bpow(ll a, ll b) {
    if (b == 0)
        return 1;
    long long res = bpow(a, b / 2);
    if (b % 2)
        return (res * res)%MOD * a %MOD;
    else
        return res * res % MOD;
}

void solve (){
    int n;
    cin >> n;
    ll mx = n*(n+1);
    if(mx % 4 != 0){
        cout << 0;
        return;
    }
    mx/=4;
    vector<vector<ll>> dp(n+1,vector<ll>(mx+1,0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= mx; j++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0) (dp[i][j] += dp[i-1][j-i]) %= MOD;
        }
    }
    cout << (dp[n][mx] * bpow(2,MOD-2))%MOD;

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}