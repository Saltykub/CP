#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
set<int> adj[N];
vector<int> vis(N,0);
bool loop = false;
void dfs(int node,int p){
    if(vis[node]){
        //cout << node;
        loop = true;
        return;
    } 
    vis[node] = 1;
    for(auto u:adj[node]){
        if(u != p) dfs(u,node);
    }
    return;
}
void solve (){
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) {adj[i].clear(), vis[i] = 0;}
    for(int i = 1; i <= n; i++){
        int u;
        cin >> u;
        adj[i].insert(u);
        adj[u].insert(i);
    }
    int l = 0, nl = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            loop = false;
            dfs(i,-1);
            if(loop) l++;
            else nl++;
        }
    }
    if(nl >= 1) cout << l+1 << " " << l+nl << "\n";
    else cout << l << " " << l + nl << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}