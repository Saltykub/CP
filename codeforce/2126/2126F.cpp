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
vector<ll> pa(N);
void dfs(int node,int p){
    pa[node] = p;
    for(auto u:adj[node]){
        if(u != p) dfs(u,node);
    }
}
void solve (){
    int n,q;
    cin >> n >> q;
    vector<int> c(n+1,0);
    map<pii,int> mp, mp2;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        adj[i].clear();
        pa[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        ll u,v,col;
        cin >> u >> v >> col;
        if(c[u] != c[v]) ans+=col;
        mp2[{u,v}] = col;
        mp2[{v,u}] = col;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++){
        for(auto u:adj[i]){
            if(u != pa[i]){
                mp[{i,c[u]}]+=mp2[{i,u}];
            }
        }
    }
    while(q--){
        int node,col;
        cin >> node >> col;
        int prev = c[node];
        // plus cur color
        ans += mp[{node,prev}];
        if(c[pa[node]] == prev) ans += mp2[{node,pa[node]}];
        mp[{pa[node],prev}] -= mp2[{node,pa[node]}];
        mp[{pa[node],col}] += mp2[{node,pa[node]}];
        if(c[pa[node]] == col) ans -= mp2[{node,pa[node]}];
        ans -= mp[{node,col}];
        c[node] = col;
        cout << ans << "\n";
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