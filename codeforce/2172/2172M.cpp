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
const int N = 2e5+10;
bool CASE = false;
vll adj[N];
vll vis(N), dis(N,INT_MAX);
void solve (){
    int n,m,k;
    cin >> n >> m >> k;
    vll a(n);
    for(auto &u:a) cin >> u;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto u:adj[node]){
            if(vis[u]) continue;
            if(dis[u] > dis[node]+1){
                dis[u] = dis[node]+1;
                q.push(u);
            }
        }
    }
    vll ret(k,0);
    for(int i = 1; i <= n; i++){
        //cout << dis[i] << " ";
        //cout << "PASS";
        int idx = a[i-1]-1;
        ret[idx] = max(ret[idx],dis[i]);
    }
        for(auto u:ret) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}