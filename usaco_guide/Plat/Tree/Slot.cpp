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
const int N = 3e5+10;
bool CASE = false;
vll adj[N];
vll lv(N,0);
ll pa[N][30];
void dfs(int node, int p){
    for(auto u:adj[node]){
        if(u == p) continue;
        pa[u][0] = node;
        lv[u] = lv[node]+1;
        dfs(u,node);
    }
}
int jmp(int a, int k){
    for(int i = 0; i < 30; i++){
        if((1LL<<i)&k){
            a = pa[a][i];
        }
    }
    return a;
}
int lca(int a, int b){
    if(lv[a] < lv[b]) swap(a,b);
    // lv[a] > lv[b], jmp a to b
    for(int i = 29; i >= 0; i--) if(lv[pa[a][i]] >= lv[b]) a = pa[a][i];
    if(a == b) return a;
    for(int i = 29; i >= 0; i--) if(pa[a][i] != pa[b][i]) a = pa[a][i], b = pa[b][i];
    return pa[a][0];
}

void solve (){
    int n,q;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);

    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= n; j++){
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    //cout << pa[3][2];
    cin >> q;
    while(q--){
        int u,v,k;
        cin >> u >> v >> k;
        int l = lca(u,v);
        int dis = lv[u]-lv[l] + lv[v] - lv[l];
        if(dis <= k) cout << v;
        else if(k <= lv[u]-lv[l]){
            cout << jmp(u,k);
        }
        else {
            k-=(lv[u]-lv[l]);
            cout << jmp(v,lv[v]-lv[l]-k);
        }
        cout << "\n";
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