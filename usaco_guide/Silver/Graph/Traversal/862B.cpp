#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> adj[N];
vector<int> col(N,0);
void dfs(int node,int prev){
    if(col[node] != 0) return;
    if(prev == -1 || prev == 2) col[node] = 1;
    if(prev == 1) col[node] = 2;
    for(auto u:adj[node]){
        dfs(u,col[node]);
    }
    return;
}
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    ll o = 0, t = 0;
    for(int i = 1; i <= n; i++){
        if(col[i] == 1) o++;
        else t++;
    }
    cout << o*t-n+1;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}