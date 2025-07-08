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
    int m,n;
    cin >> n >> m;
    vector<int> path;
    vector<int> adj[n+1];
    vector<int> in(n+1,0);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        in[v]++;
        adj[u].pb(v);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int fr = q.front();
        path.pb(fr);
        q.pop();
        for(auto u:adj[fr]){
            in[u]--;
            if(in[u] == 0) q.push(u);
        }
    }
    for(int i =  1; i <= n; i++){
        if(in[i] != 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for(auto u:path) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}