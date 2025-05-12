#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
int lv[N], cnt[N], lift[N][21], ans[N];
void dfs(int node,int p,int cur){
    lv[node] = cur;
    lift[node][0] = p;
    for(auto u:adj[node]){
        if(u == p)continue;
        dfs(u,node,cur+1);
    }
}
int lca(int a,int b){
    if(lv[a] < lv[b])swap(a,b);
    for(int i = 19; i >= 0; i--) if(lv[lift[a][i]] >= lv[b]) a = lift[a][i];
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(lift[a][i] != lift[b][i]){
            a = lift[a][i];
            b = lift[b][i];
        }
    }
    return lift[a][0];
}
void dfs2(int node,int p){
    for(auto u:adj[node]){
        if(u == p)continue;
        dfs2(u,node);
        ans[node] += ans[u];
    }
}
int main(){
    int n,q;
    cin >> n >> q;
    for(int i=1; i < n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1,1);
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
           lift[j][i] = lift[lift[j][i-1]][i-1];
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        int pa = lca(a,b);
        //cout << pa << endl;
        ans[a]++;
        ans[b]++;
        ans[pa]--;
        if(pa != 1) ans[lift[pa][0]]--;
    }
    dfs2(1,1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";

}