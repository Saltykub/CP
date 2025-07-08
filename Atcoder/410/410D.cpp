#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2000;
bool CASE = false;
vector<pii> adj[N];
bool dp[N][N];
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    queue<pii> q;
    q.push({1,0});
    dp[1][0] = 1;
    while(!q.empty()){
        auto [node,cur] = q.front();
        q.pop();
        for(auto [v,w]:adj[node]){
            if(dp[v][w^cur] == 0){
                dp[v][w^cur] = 1;
                q.push({v,w^cur});
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(dp[n][i]){
            cout << i;
            return;
        }
    }
    cout << -1;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}