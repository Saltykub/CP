#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int o = 0,z = 0,q = 0;
vector<int> vis(N,false);
vector<int> adj[N];
vector<char> c;
void dfs(int node,int p){
    if(vis[node]) return;
    vis[node] = true;
    for(auto u:adj[node]){
        if(u == p) continue;
        dfs(u,node);
    }
    if(adj[node].size() == 1 && node != p) {
        if(c[node] == '0') z++;
        else if(c[node] == '1') o++;
        else q++;
    }
    return;
}
void solve (){
    o = 0,z = 0,q = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    string s;
    cin >> s;
    c.pb('a');
    int qq = 0;
    for(auto u:s) {
        c.pb(u); 
        if(u == '?') qq++;
    }
    dfs(1,1);
    if(c[1] == '0'){
        cout << o+(ceil(1.0*q/2)) << "\n";
    }
    else if(c[1] == '1'){
        cout << z+(ceil(1.0*q/2)) << "\n";
    }
    else {
        if(z == o) cout << z + (q + qq % 2)/ 2<< "\n";
        else cout << max(z,o) + q/2 << "\n";
    }
    for(int i = 1; i<=n; i++){
        adj[i].clear();
        vis[i] = false;
    }
    c.clear();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }

}