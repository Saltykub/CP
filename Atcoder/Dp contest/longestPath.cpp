#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define NL "\n"
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> adj[N];
vector<int> in(N,0), dp(N,-1);
int dfs(int node){
    if(dp[node] != -1) return dp[node];
    int ret = 0;
    for(auto u:adj[node]){
        ret = max(ret,dfs(u)+1);
    }
    return dp[node] = ret;
}
void solve (){
    int n,m;
    cin >> n >> m;
    while(m--) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) dfs(i);
    for(int i = 1; i <= n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}