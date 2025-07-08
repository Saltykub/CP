#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e3+10;
bool CASE = false;
vector<int> p(N);
vector<pii> adj[N];
vector<vector<ll>> dis(N,vector<ll>(N,0));
int fp(ll n) {
    if(p[n] == n) return n;
    return p[n] = fp(p[n]);
}

bool merge(int u,int v){
    int pu = fp(u), pv = fp(v);
    if(pv != pu){
        p[pv] = pu;
        return true;
    }
    return false;
}

void dfs(int node,int p,int src){
    for(auto [v,w]:adj[node]){
        if(v != p){
            dis[src][v] += dis[src][node] + w;
            dfs(v,node,src);
        }
    }
}

void solve (){
    int n;
    cin >> n;
    vector<vector<ll>> tab(n+1,vector<ll>(n+1,0));
    
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> tab[i][j];
    bool can = true;
    vector<piii> edge;
    for(int i = 1; i <= n; i++){
        if(tab[i][i] != 0) can = false;
        p[i] = i;
        for(int j = i+1; j <= n; j++){
            if(tab[i][j] != tab[j][i] || tab[i][j] == 0) {
               can = false;
            }
            edge.pb({tab[i][j],{i,j}});
        }
    }
    sort(edge.begin(),edge.end());
    for(auto e:edge){
        auto [w,uv] = e;
        auto [u,v] = uv;
        if(merge(u,v)){
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
    }
    for(int i = 1; i <= n; i++){
        dfs(i,i,i);
        for(int j = 1; j <= n; j++) if(dis[i][j] != tab[i][j]) can = false;
    }
    if(can) cout << "YES";
    else cout << "NO";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}