#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = true;
int lca;
vector<int> adj[N];
int depth[N];
vector<int> l;
ll bpow(int a,int b){
    if(b == 0) return 1;
    if(b%2) return bpow(a,b/2) * bpow(a,b/2) % MOD * a % MOD;
    return bpow(a,b/2) * bpow(a,b/2) % MOD;
}
void dfs(int node, int p){
    if(adj[node].size() > 2) lca = node;
    depth[node] = depth[p]+1;
    bool leaf = true;
    for(auto u:adj[node]){
        if(u == p) continue;
        leaf = false;
        dfs(u,node);
    }
    if(leaf) l.pb(node);
}
void solve (){
    int n;
    cin >> n;
    lca = 1;
    for(int i = 0; i <= n; i++) {adj[i].clear(); depth[i] = 0;}
    l.clear();
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    if(l.size() > 2) cout << 0 << "\n";
    else if(l.size() == 1) {
        cout << bpow(2,n) << "\n";
    }
    else {
        if(depth[l[0]] == depth[l[1]]){
            cout <<  bpow(2,depth[lca]+1) << "\n";
        }
        else {
            int d1 = depth[l[0]], d2 = depth[l[1]];
            d1 -= depth[lca], d2 -= depth[lca];
            int diff = abs(d1-d2);
            cout << (bpow(2,diff) + bpow(2,diff+1))%MOD * bpow(2,depth[lca]-1) % MOD << "\n";
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