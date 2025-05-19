#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
const int M = 101;
const int MOD = 1e9+7;
bool CASE = false;
ll dp[N][M]; // dp[i][j] =  number that sastify the condition that from 1 to i and end with j
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n+1,0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    if(arr[1] != 0) dp[1][arr[1]] = 1;
    else {
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(arr[i] == 0) {
            for(int j = 1; j <= m; j++){
                if(j != 1) (dp[i][j] += dp[i-1][j-1]) %= MOD;
                if(j != m) (dp[i][j] += dp[i-1][j+1]) %= MOD;
                (dp[i][j] += dp[i-1][j]) %= MOD;
            }
        }
        else {
            if(arr[i] != 1) (dp[i][arr[i]] += dp[i-1][arr[i]-1]) %= MOD;
            if(arr[i] != m) (dp[i][arr[i]] += dp[i-1][arr[i]+1]) %= MOD;
            (dp[i][arr[i]] += dp[i-1][arr[i]]) %= MOD;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        (ans += dp[n][i]) %= MOD;
    }
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