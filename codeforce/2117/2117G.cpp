#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const ll INF = 1e17;
bool CASE = true;
vector<pii> adj[N];
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) adj[i].clear();
    while(m--){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<ll> dis(n+1,INF), dis2(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto[cur,node] = pq.top();
        pq.pop();
        if(cur > dis[node]) continue;
        for(auto [v,w]:adj[node]){
            if(dis[v] > max(cur,w)){
                dis[v] = max(cur,w);
                pq.push({dis[v],v});
            }
        }
    }
    pq.push({0,n});
    while(!pq.empty()){
        auto[cur,node] = pq.top();
        pq.pop();
        if(cur > dis2[node]) continue;
        for(auto [v,w]:adj[node]){
            if(dis2[v] > max(cur,w)){
                dis2[v] = max(cur,w);
                pq.push({dis2[v],v});
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i <= n; i++){
        for(auto [v,w]:adj[i]){
            ans = min(ans,w+max({dis[i],dis2[v],w}));
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