#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<ll> adj[N];
vector<ll> dp(N),arr(N);
void dfs(ll node, ll p, ll k,ll val){
    if(k == 1){
        if(val > 0) dp[node] += val;
        for(auto u:adj[node]){
            if(u == p) continue;
            dfs(u,node,-k,dp[node]);
        }
    }
    else {
        for(auto u:adj[node]){
            if(u == p) continue;
            dfs(u,node,-k,val-arr[node]);
        }
    }
}
void solve (){
    int n;
    cin >> n;
    arr.resize(n+1,0);
    dp.resize(n+1,0);
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,1,0);
    dfs(1,-1,-1,0);
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}