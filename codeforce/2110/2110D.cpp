#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> batt(n+1);
    vector<pii> adj[n+1];
    for(int i = 1; i <= n; i++) cin >> batt[i];
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    
    auto bfs = [&](int mx){
        queue<pii> q;
        q.push({1,min(batt[1],mx)});
        vector<int> dis(n+1,0);
        dis[1] = min(batt[1],mx);
        bool can = false;
        while(!q.empty()){
            auto [node,cur] = q.front();
            q.pop();
            if(cur < dis[node]) continue;
            for(auto vw:adj[node]){
                auto [v,w] = vw;
                int nxt = min(batt[v] + cur,mx*1LL);
                if(cur >= w && dis[v] < nxt){
                    if(v == n) return true;
                    dis[v] = nxt;
                    q.push({v,dis[v]});
                }
            }
        }
        return false;
    };
    ll l = 1, r = 1e9+2; 
    while(l < r){
        int mid = (l+r)/2;
        //cout << l << " "<< mid << " " << r << "\n";
        if(bfs(mid)) r = mid;
        else l = mid+1;
        
    }
    if(l == 1e9+2) cout << -1;
    else cout << l;
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