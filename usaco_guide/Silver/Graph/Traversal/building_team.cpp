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
vector<int> col(N,0);
bool can = true;
void dfs(int node, int prev){
    if(prev == 0) col[node] = 1;
    if(prev == 1){
        if(col[node] == 1) {
            can = false;
            return;
        }
        if(col[node] == 2)return;
        col[node] = 2;
    }
    if(prev == 2){
        if(col[node] == 2) {
            can = false;
            return;
        }
        if(col[node] == 1) return;
        col[node] = 1;
    }
    for(auto u:adj[node]){
        dfs(u,col[node]);
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
    for(int i = 1; i <= n; i++){
        if(col[i] == 0) dfs(i,0);
    }
    if(!can){
        cout << "IMPOSSIBLE";
        return;
    }
    for(int i = 1; i <= n; i++) cout << col[i] << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}