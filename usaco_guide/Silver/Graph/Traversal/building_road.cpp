#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> adj[N];
vector<int> vis(N,0);

void dfs(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto u:adj[node]){
        dfs(u);
    }
    return;
}

void solve (){
    ll n,m;
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pii> ans;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            if(i!=1) ans.pb({1,i});
        }
    }
    cout << ans.size() << "\n";
    for(auto u:ans) cout << u.st << " " << u.nd << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}