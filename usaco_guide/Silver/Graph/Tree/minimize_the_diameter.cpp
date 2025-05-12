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
int dis,e;
void dfs(int u, int p, int depth) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, depth + 1);
	}

	if (depth > dis) {
		dis = depth;
		e = u;
	}
}
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1, 0);
	dis = 0;
	dfs(e, -1, 0);
    int dis1 = dis;
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) adj[i].clear();
    for(int i = 0; i < m-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dis = 0;
    dfs(1, -1, 0);
	dis = 0;
	dfs(e, -1, 0);
    int dis2 = dis;
    cout << max({(dis1+1)/2 + (dis2+1)/2 + 1,dis1,dis2});

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}