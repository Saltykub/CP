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
ll dp[(1<<20)][21]; // dp[i][j] mean number of route that visited all subset i and end with jth  city 
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[--v].pb(--u);
    }
    dp[1][0] = 1;
    for(int i = 2; i < (1<<n); i++){
        if((i&(1<<0)) == 0) continue;
        if((i&(1<<(n-1))) && i!=((1<<n)-1)) continue;
        for(int j = 0; j < n; j++){
            if((i&(1<<j)) == 0) continue;
            int prev = i - (1<<j);
            for(auto u:adj[j]){
                if((i & (1<<u))){
                    dp[i][j] += dp[prev][u];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}