#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 5e4+10;
bool CASE = false;
vll adj[N];
ll dp[N][510]; // path length jth that end with ith
ll ans, k;
void dfs(int v, int p){
    dp[v][0] = 1;
    for(auto u:adj[v]){
        if(u == p) continue;
        dfs(u,v);
        for(int i = 0; i < k; i++) {
            ans += dp[v][i] * dp[u][k-i-1];
            if(dp[v][i] != 0){
                cout << v << " " << i << " " << dp[v][i] << "\n";
            }
        }
        // ans += dp[u][k-1];
        for(int i = 0; i < k; i++) dp[v][i+1] += dp[u][i];
    }
}
void solve (){
    int n;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
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