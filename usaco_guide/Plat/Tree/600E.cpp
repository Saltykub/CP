#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 1e5+10;
bool CASE = false;
vll c(N);
vll adj[N];
map<int,int> mp[N];
vll ans(N,0), mx(N,0);
void dfs(int node, int p){
    for(auto u:adj[node]){
        if(u == p) continue;
        dfs(u,node);
        if(sz(mp[node]) < sz(mp[u])){
            mx[node] = mx[u];
            ans[node] = ans[u];
            swap(mp[node],mp[u]);
        }
        for(auto [a,b]:mp[u]) {
            mp[node][a] += b;
            if(mp[node][a] > mx[node]){
                mx[node] = mp[node][a];
                ans[node] = a;
            }
            else if(mp[node][a] == mx[node]){
                ans[node] += a;
            }
        }
    }
    mp[node][c[node]]++;
    if(mp[node][c[node]] > mx[node]){
        ans[node] = c[node];
        mx[node] = mp[node][c[node]];
    }
    else if(mp[node][c[node]] == mx[node]){
        ans[node] += c[node];
    }
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
   // cout << mx[3] << " ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}