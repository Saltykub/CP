#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<pii> adj[N];
vector<int> h(N,0);
ll d[N][2],d2[N][2];
void solve (){
    int n,m,hh;
    cin >> n >> m >> hh;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        h[i] = false;
        d[i][0] = d[i][1] = LLONG_MAX;
        d2[i][0] = d2[i][1] = LLONG_MAX;
    }
    for(int i = 0; i < hh; i++) {
        int x;
        cin >> x;
        h[x] = 1;
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    d[1][h[1]] = 0;
    pq.push({0,{1,h[1]}});
    while(!pq.empty()){
        auto [dis,p] = pq.top();
        auto [node,curh] = p;
        pq.pop();
        if(d[node][curh] < dis) continue;
        for(auto u:adj[node]){
            auto [w,v] = u;
            if(curh){
                if(dis + w/2 < d[v][curh]){
                    d[v][curh] = dis+w/2;
                    pq.push({d[v][curh],{v,curh}});
                }
            }
            else {
                if(dis + w < d[v][h[v]]){
                    d[v][h[v]] = dis + w;
                    pq.push({d[v][h[v]],{v,h[v]}});
                }
            }
        }
    }
    d2[n][h[n]] = 0;
    pq.push({0,{n,h[n]}});
    while(!pq.empty()){
        auto [dis,p] = pq.top();
        auto [node,curh] = p;
        pq.pop();
         if(d2[node][curh] < dis) continue;
        for(auto u:adj[node]){
            auto [w,v] = u;
            if(curh){
                if(dis + w/2 < d2[v][curh]){
                    d2[v][curh] = dis+w/2;
                    pq.push({d2[v][curh],{v,curh}});
                }
            }
            else {
                if(dis + w < d2[v][h[v]]){
                    d2[v][h[v]] = dis + w;
                    pq.push({d2[v][h[v]],{v,h[v]}});
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if((d[i][0] == INT_MAX && d[i][1] == INT_MAX) || (d2[i][0] == INT_MAX && d2[i][1] == INT_MAX)) continue;
        //cout << d[i] + d2[i] << "\n";
        ans = min(max(min(d[i][0],d[i][1]),min(d2[i][0],d2[i][1])),ans);
    }
    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;
    cout << "\n";
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}