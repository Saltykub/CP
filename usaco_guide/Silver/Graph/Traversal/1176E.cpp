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
    vector<int> adj[n+1];
    vector<int> col(n+1,0);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    vector<int> o,t;
    q.push(1);
    col[1] = 1;
    o.pb(1);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto u:adj[top]){
            if(col[u]) continue;
            if(col[top] == 1) col[u] = 2,t.pb(u);
            else col[u] = 1,o.pb(u);
            q.push(u);
        }
    }
    if(o.size() < t.size()) swap(t,o);
    cout << t.size() << "\n";
    for(auto u:t) cout << u << " ";
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