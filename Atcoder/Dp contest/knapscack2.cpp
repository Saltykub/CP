#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
bool CASE = false;
ll dp[110][N]; // dp[i][j] = minweight consider item [i] with sum val =  [j]
void solve (){
    int n, mxw; 
    cin >> n >> mxw;
    for(int i = 0; i <= 100; i++) for(int j = 0; j < N; j++) dp[i][j] = INT_MAX;
    vector<ll> w(n+1),v(n+1);
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < N; j++){
            dp[i][j] = dp[i-1][j];
            if(j-v[i] >= 0) dp[i][j] = min(dp[i][j],dp[i-1][j-v[i]] + w[i]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) if(dp[n][i] <= mxw) ans = i;
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