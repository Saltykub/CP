#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 3e5+10;
bool CASE = false;
int ti = 1;
vector<int> adj[N];
vector<int> fw(N);
vector<int> in(N), out(N);
void tour(int node,int prev){
    in[node] = ti++;
    for(auto u:adj[node]){
        if(u != prev) tour(u,node);
    }
    out[node] = ti;
}
void add(int i,int val){
    for(; i < N; i += (i&-i)){
        fw[i]+=val;
    }
}
int query(int i){
    int ret = 0;
    for(;i; i-=(i&-i)){
        ret += fw[i];
    }
    return ret;
}
int sum(int l,int r){
    return query(r)-query(l-1);
}
void solve (){
    int n;
    cin >> n;
    vector<pii> edge(n);
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        edge[i] = {u,v};
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tour(1,0);
    for(int i = 1; i <= n; i++) {add(i,1);}
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x,w;
            cin >> x >> w;
            add(in[x],w);
            //cout << "PASS1";
        }
        else {
            int y;
            cin >> y;
            auto [u,v] = edge[y];
            if(in[u] > in[v]) swap(u,v);
            cout << abs(sum(in[1],out[1]-1)-2*sum(in[v],out[v]-1)) << "\n";
            //cout << "PASS2";
        }
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