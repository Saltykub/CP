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
vector<double> ans;
void dfs(int node,int p,int depth, double prob){
    if(vis[node]) return;
    vis[node] = 1;
    if(adj[node].size() == 1 && adj[node][0] == p){
        ans.pb(depth*prob);
        return;
    }
    for(auto u:adj[node]){
        if(node == 1)dfs(u,node,depth+1,prob*(1.0/adj[node].size()));
        dfs(u,node,depth+1,prob*(1.0/(adj[node].size()-1)));
    }
    return;
}
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1,0,1);
    double sm = 0;
    for(auto u:ans) sm+=u;
    printf("%.12f",sm);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}