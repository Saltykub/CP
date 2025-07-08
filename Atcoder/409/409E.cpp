#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<pii> adj[N];
vector<ll> x(N);
vector<ll> dis(N,0);
void dfs(int node,int p){
    for(auto [v,w]:adj[node]){
        if(v == p) continue;
        dfs(v,node);
        dis[node] += abs(x[v])*w + dis[v];
        x[node] += x[v];
    }
    return;
}
void solve (){
    int n;
    cin >> n;
    x.resize(n+1,0);
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 0; i < n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,1);
    cout << dis[1];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}