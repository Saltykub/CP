#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> adj[N], radj[N];
vector<int> vis(N,0);
int compo[N];
int com = 0;
stack<int> s;
void dfs(int node){
    if(vis[node]) return;
    vis[node] = 1;
    for(auto u:adj[node]){
        dfs(u);
    }
    s.push(node);
    return;
}
void dfs2(int node){
    if(vis[node]) return;
    vis[node] = 1;
    compo[node] = com;
    for(auto u:radj[node]){
        dfs2(u);
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
        radj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++) vis[i] = 0;
    int start = s.top();
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(!vis[node]){
            //cout << node << "\n";
            dfs2(node);
            com++;
        }
    }
    if(com == 1) cout << "YES";
    else {
        int target = 0;
        for(int i = 1; i <= n; i++){
            vis[i] = false;
            if(compo[i] != 0) target = i;
        }
        cout << "NO\n";
        dfs(start);
        if(!vis[target]) {
            cout << start << " " << target;
        }
        else cout << target << " " << start;
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