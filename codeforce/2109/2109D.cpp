#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> adj[N];
void solve (){
    int n,m,l;
    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) adj[i].clear();
    vector<pii> dis(n+1,{0,0});
    ll sm = 0, mno = LLONG_MAX;
    for(int i = 0; i < l; i++) {
        ll x;
        cin >> x;
        sm += x;
        if(x%2) mno = min(mno,x);
    }
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<pii> q;
    q.push({1,0});
    while(!q.empty()){
        auto [node,d] = q.front();
        // cout << node << " " << d << "\n";
        q.pop();
        if(d%2 && dis[node].st < d) continue;
        if(!d%2 && dis[node].nd < d && node!=1) continue;
        for(auto u:adj[node]){
            if(d%2){
                if(!dis[u].nd) {
                    dis[u].nd = d+1;
                    q.push({u,dis[u].nd});
                }
            }
            else {
                if(!dis[u].st) {
                    dis[u].st = d+1;
                    q.push({u,dis[u].st});
                }
            }
        }   
    }
    string ans = "1";
    ll mxo = -1, mxe = -1;
    if(sm%2){
        mxo = sm;
        mxe = sm - mno;
    }
    else {
        if(mno != LLONG_MAX) mxo = sm-mno;
        mxe = sm;
    }
    for(int i = 2; i <= n; i++){
        bool can = false;
        if(dis[i].st != 0){
            if(dis[i].st <= mxo) can = true;
        }
        if(dis[i].nd != 0){
            if(dis[i].nd <= mxe) can = true;
        }
        if(can) ans += "1";
        else ans += "0";
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