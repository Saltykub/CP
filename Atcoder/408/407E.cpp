#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<pii> adj[N];
void solve (){
    int n,m;
    cin >> n >> m;
    vector<pair<pii,int>> edge;
   
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.pb({{u,v},w});
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    ll ext = 0;
    for(int i = 30; i >= 0; i--){
        queue<pii> q;
        vector<int> dis(n+1,INT_MAX);
        q.push({1,0});
        dis[1] = 0;
        int cnt = 0;
        while(!q.empty()){
            auto [node,cur] = q.front();
            q.pop();
            if(dis[node] < cur) continue;
            for(auto [v,w]:adj[node]){
                if((1LL<<i)&w) continue;
                if(dis[v] == INT_MAX || dis[v] > cur+1){
                    dis[v] = cur+1;
                    q.push({v,cur+1});
                }
            }
        }
        if(dis[n] != INT_MAX){
            ext += (1LL<<i);
            for(int j = 1; j <= n; j++) adj[j].clear();
            for(int j = 0; j < m; j++){
                auto [uv,w] = edge[j];
                auto [u,v] = uv;
                if(ext&w) continue;
                adj[u].pb({v,w});
                adj[v].pb({u,w});
            }
        }
        else {
            ans += (1<<i);
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