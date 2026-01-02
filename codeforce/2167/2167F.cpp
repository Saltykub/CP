#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define vll vector<ll> 
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> adj[N];
void solve (){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> sz(n+1,1),pa(n+1,0);
    sz[0] = 0;
    function<void(int,int)> dfs = [&](int u, int p){
        pa[u] = p;
        for(auto v:adj[u]){
            if(v == p) continue;
            dfs(v,u);
            sz[u] += sz[v];
        }
        return;
    };
    dfs(1,0);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto u:adj[i]){
            if(u == pa[i]){
                if(sz[i] >= k){
                    ans += n-sz[i];
                }
            }
            else {
                if(n-sz[u] >= k){
                    ans += sz[u];
                }
            }
        }
        //cout << ans << "\n";
    }
    cout << ans+n<< "\n";
    for(int i = 1; i <= n; i++) adj[i].clear();

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}