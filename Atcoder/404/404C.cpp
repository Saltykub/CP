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
        if(vis[u]) continue;
        dfs(u);
    }
    return;
}
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n != m) {
        cout << "No";
    }
    else {
        for(int i = 0; i < n; i++) {
            if(adj[i].size() != 2) {
                cout << "No";
                return;
            }
        }
        dfs(0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cout << "No";
                return;
            }
        }
        cout << "Yes";
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