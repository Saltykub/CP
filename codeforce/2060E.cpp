#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> adj1[N], adj2[N];
int p[N], p2[N];
int fp(int node){
    if(p[node] == node) return node;
    return p[node] = fp(p[node]);
}
int fp2(int node){
    if(p2[node] == node) return node;
    return p2[node] = fp(p2[node]);
}
void dfs1(int node,int val){
    if(p[node]) return;
    p[node] = val;
    for(auto u:adj1[node]){
        dfs1(u,node);
    }
    return;
}
void dfs2(int node,int val){
    if(p2[node]) return;
    p2[node] = val;
    for(auto u:adj2[node]){
        dfs2(u,node);
    }
    return;
}
void solve (){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= n; i++){
        adj1[i].clear();
        adj2[i].clear();
        p[i] = 0;
        p2[i] = 0;
    }
    for(int i = 0; i < m1; i++){
        int u,v;
        cin >> u >> v;
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    for(int i = 0; i < m2; i++){
        int u,v;
        cin >> u >> v;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(p2[i] == 0) dfs2(i,i);
    }
    for(int i = 1; i <= n; i++){
        if(!p[i]) dfs1(i,i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int p1 = fp(i), p2 = fp2(i);
       // cout << p1 << " " << p2 << "\n";
        if(p1 != p2){
            p[i] = p2;
            ans++;
            if(p2 != i) ans++;
        }
    }
    cout << ans << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}