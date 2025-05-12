#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
set<int> unvis;
set<int> adj[N];
int cur = 0;
void dfs(int node){
    cur++;
    auto it = unvis.begin();
    while(it != unvis.end()){
        if(adj[node].find(*it) != adj[node].end()){
            it++;
        }
        else {
            auto go = *it;
            unvis.erase(it);
            dfs(go);
            it = unvis.upper_bound(go);
        }
    }
}
void solve (){
    ll n,m;
    cin >> n >> m;
    vector<int> ans;
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i = 1; i <= n; i++) unvis.insert(i);
    for(int i = 1; i <= n; i++){
        if(unvis.find(i) != unvis.end()){
            cur = 0;
            unvis.erase(i);
            dfs(i);
            ans.pb(cur);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto u:ans) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}