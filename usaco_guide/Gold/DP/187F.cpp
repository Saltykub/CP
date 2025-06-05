#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> adj(n,0);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u] |= (1<<v);
        adj[v] |= (1<<u);
    }
    // precompute all complete graph
    vector<int> dp(1<<n,INT_MAX);
    for(int mask = 0; mask < (1<<n); mask++){
        bool con = true;
        for(int u = 0; u < n; u++){
            if(((1<<u)&mask)){
                if(((adj[u] | (1<<u)) & mask) != mask){
                    con = false;
                    break;
                }
            }
        }
        if(con) dp[mask] = 1;
    }
    for(int mask = 0; mask < (1<<n);  mask++){
        for(int submask = mask; submask; submask = (submask-1)&mask){
            int subset = submask ^ mask;
            if(dp[subset] != INT_MAX && dp[submask] != INT_MAX){
                dp[mask] = min(dp[mask],dp[submask] + dp[subset]);
            }
        }
    }
    cout << dp[(1<<n)-1];


}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}