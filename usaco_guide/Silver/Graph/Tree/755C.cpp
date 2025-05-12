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
    vis[node] = 1;
    for(auto u:adj[node]) dfs(u);
    return;
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u;
        cin >> u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
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