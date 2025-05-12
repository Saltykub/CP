#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
int sz[N];
void dfs(int node,int p = -1){
    for(auto u:adj[node]){
        if(u == p)continue;
        dfs(u,node);
        sz[node] += sz[u];
    }
}
int centroid(int node,int n,int p = -1){
    for(auto u:adj[node]){
        if(u == p) continue;
        if(sz[u] * 2 > n) return centroid(u,n,node);
    }
    return node;
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i < n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)sz[i] = 1;
    dfs(1);
    cout << centroid(1,n);
    

}