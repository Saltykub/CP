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
const int N = 1e5+10;
bool CASE = false;
vll adj[N];
vll lv(N,0);
ll pa[N][20];
vll mn[N][20];
vll ppl[N];
void merge(vector<ll>& a, const vector<ll>& b){
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if(a.size() > 10) a.resize(10);
}

void dfs(int node, int p){
    for(auto u:adj[node]){
        if(u == p) continue;
        pa[u][0] = node;
        vll tmp;
        for(int i = 0; i < min(sz(ppl[u]),10); i++) tmp.pb(ppl[u][i]);
        for(int i = 0; i < min(sz(ppl[node]),10); i++) tmp.pb(ppl[node][i]);
        sort(all(tmp));
        for(int i = 0; i < min(10,sz(tmp)); i++) mn[u][0].pb(tmp[i]);
        lv[u] = lv[node]+1;
        dfs(u,node);
    }
}
vll jmp(int a, int k){
    vll tmp;
    for(int i = 0; i < 20; i++){
        if((1LL<<i)&k){
            merge(tmp,mn[a][i]);
            a = pa[a][i];
        }
    }
    return tmp;
}
int lca(int a, int b){
    if(lv[a] < lv[b]) swap(a,b);
    // lv[a] > lv[b], jmp a to b
    for(int i = 19; i >= 0; i--) if(lv[pa[a][i]] >= lv[b]) a = pa[a][i];
    if(a == b) return a;
    for(int i = 19; i >= 0; i--) if(pa[a][i] != pa[b][i]) a = pa[a][i], b = pa[b][i];
    return pa[a][0];
}

void solve (){
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= m; i++){
        int c;
        cin >> c;
        ppl[c].pb(i);
    }
    for(int i = 1; i <= n; i++) sort(all(ppl[i]));
    dfs(1,0);
   
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            pa[j][i] = pa[pa[j][i-1]][i-1];
            merge(mn[j][i],mn[pa[j][i-1]][i-1]);
            merge(mn[j][i],mn[j][i-1]);
        }
    }

    while(q--){
        int u,v,k;
        cin >> u >> v >> k;
        if(u == v){
            cout << min(sz(ppl[u]),k) << " ";
            for(int i = 0; i < min(sz(ppl[u]),k); i++) cout << ppl[u][i] << " ";
            cout << "\n";
            continue;
        }
        int l = lca(u,v);
       // cout << lv[u] << " " << lv[v] << " " << l  << "\n";
        int disu = lv[u]-lv[l], disv = lv[v]-lv[l];
        vll ans;
        merge(ans,jmp(u,disu));
        merge(ans,jmp(v,disv));
        cout << min(sz(ans),k) << " ";
        for(int i = 0; i < min(sz(ans),k); i++) cout << ans[i] << " ";
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