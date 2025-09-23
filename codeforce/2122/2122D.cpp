#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<pii,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e3+10;
bool CASE = true;
vector<int> adj[N];
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) adj[i].clear();
    vector<vector<ll>> order(n+1,vector<ll>(n+1,0));
    vector<ll> cnt(n+1,0);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        order[u][v] = ++cnt[u];
        order[v][u] = ++cnt[v];
    }
    vector<ll> dis(n+1,LLONG_MAX), wait(n+1,LLONG_MAX);
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({{0,0},1});
    dis[1] = 0, wait[1] = 0;
    while(!pq.empty()){
        auto [tt,node] = pq.top();
        auto [t,wwt] = tt;
        pq.pop();
        if(t > dis[node]) continue;
        if(t == dis[node] && wwt > wait[node]) continue;
        for(auto u:adj[node]){
            ll d = order[node][u], sz = adj[node].size();
            ll curt = t%sz+1;
            ll wt = (d-curt+sz)%sz;
            if(t+wt+1 < dis[u]){
                dis[u] = t+wt+1;
                wait[u] = wt+wwt;
                pq.push({{dis[u],wait[u]},u});
            }
            else if(t+wt+1 == dis[u]){
                if(wt + wwt < wait[u]){
                    wait[u] = wt+wwt;
                    pq.push({{dis[u],wait[u]},u});
                }
            }
        }
    }
    cout << dis[n] << " " << wait[n] << "\n";   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}