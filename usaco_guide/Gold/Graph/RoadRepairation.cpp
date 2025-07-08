#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(N,0);
struct Edge{
    int u,v,w;
    bool operator<(Edge const&other){
        return w < other.w;
    }
};
int fp(int n){
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
void solve (){
    int n,m;
    cin >> n >> m;
    vector<Edge> edge; 
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        Edge e; e.u = u, e.v = v, e.w = w;
        edge.pb(e);
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(edge.begin(),edge.end());
    ll ans = 0;
    for(auto e:edge){
        auto[u,v,w] = e;
        if(merge(u,v)) ans += w;
    }
    for(int i = 2; i <= n; i++) {
        if(fp(i) != fp(1)) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}