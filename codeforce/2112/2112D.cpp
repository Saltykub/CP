#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> lv(N);
vector<int> p(N);
vector<int> adj[N];
void dfs(int node,int pa,int l){
    lv[node] = l;
    p[node] = pa;
    for(auto u:adj[node]){
        if(u != pa){
            dfs(u,node,l+1);
        }
    }
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) adj[i].clear();
    lv.resize(n+1,0);
    p.resize(n+1,0);
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n == 2){
        cout << "No\n";
        return;
    }
    vector<pii> ans;
    vector<int> cnt(n+1,0);
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 2){
            cout << "Yes\n";
            int u = adj[i][0], v = adj[i][1];
            ans.pb({u,i});
            ans.pb({i,v});
            dfs(u,i,1);
            dfs(v,i,0);
            for(int j = 1; j <= n; j++){
                if(j == i || p[j] == i) continue;
                if(lv[j]%2){
                    ans.pb ({j,p[j]});
                }
                else {
                    ans.pb({p[j],j});
                }
            }
            for(auto [u,v]:ans){
                cout << u << " " << v << "\n";
            }
            return;
        }
    }
    cout << "No\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}