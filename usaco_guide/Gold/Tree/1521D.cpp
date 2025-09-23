#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> adj[N];
vector<int> leaf(N);
vector<pii> add,del;
void dfs(int node,int p){
    int cnt = 0;
    for(auto u:adj[node]){
        if(u != p){
            dfs(u,node);
            cnt++;
        }
    }
    if(cnt <= 1) return;
    if(node == 1){
        if(cnt <= 2) return;
    }
}
void solve (){
    int n;
    cin >> n;
    add.clear();
    del.clear();
    for(int i = 1; i <= n; i++) adj[i].clear(), leaf[i] = i;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}