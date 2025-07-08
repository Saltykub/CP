#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define tu tuple<ll,ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
vector<pii> adj[N];
void solve (){
    int n,m;
    cin >> n >> m;
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<ll> dis(n+1,LLONG_MAX);
    vector<ll> vis(n+1,false);
    vector<ll> c(n+1,0);
    vector<ll> mx(n+1,0),mn(n+1,0);
    pq.push({0,1});
    dis[1] = 0;
    c[1] = 1;
    while(!pq.empty()){
        auto [cur,node] = pq.top();
        pq.pop();
        if(cur > dis[node]) continue;   
        for(auto [v,w]:adj[node]){
            if(dis[v] > cur + w){
                c[v] = c[node];
                dis[v] = cur+w;
                mx[v] = mx[node] + 1;
                mn[v] = mn[node] +1;
                pq.push({dis[v],v});
            }
            else if(dis[v] == cur + w){
                c[v] += c[node];
                c[v] %= MOD;
                mx[v] = max(mx[v],mx[node]+1);
                mn[v] = min(mn[v],mn[node]+1);
            }
        }
    }
    cout << dis[n] << " " << c[n] << " " << mn[n] << " " << mx[n];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}