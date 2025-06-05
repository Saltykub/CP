#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1], dis(n+1,INT_MAX), from(n+1,0);
    from[1] = -1;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<pii> q;
    q.push({1,0});
    dis[1] = 0;
    while(!q.empty()){
        auto[node,d] = q.front();
        q.pop();
        for(auto u:adj[node]){
            if(dis[u] == INT_MAX){
                dis[u] = d+1;
                from[u] = node;
                q.push({u,dis[u]});
            }
        }
    }
    if(dis[n] == INT_MAX) cout << "IMPOSSIBLE";
    else {
        cout << dis[n]+1 << "\n";
        vector<int> path;
        while(n != -1){
            path.pb(n);
            n = from[n];
        }
        reverse(path.begin(),path.end());
        for(auto p:path) cout << p << " ";
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