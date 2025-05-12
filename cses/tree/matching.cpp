#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
vector<int> adj[N];
int dp[N][2];
int vis[N];
void dfs(int node, int p){
    if(vis[node])return;
    vis[node]=1;
    int ret=0;
    for(auto u:adj[node])dfs(u,node);
    // not pick 
    for(auto u:adj[node]){
        if(u==p)continue;
        ret+=max(dp[u][0],dp[u][1]);
    }
    dp[node][0]=ret;
    ret=0;
    // pick 
    for(auto u:adj[node]){
        if(u==p) continue; 
        if(dp[u][0]>dp[u][1]){
            ret=max(ret,dp[node][0]+1);
        }
        else {
            ret=max(ret,dp[node][0]-dp[u][1]+dp[u][0]+1);
        }
    }
    dp[node][1]=ret;
    // cout << node << " 0: " <<dp[node][0] << " 1: " <<dp[node][1] << endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs(1,1);
    
    cout<<max(dp[1][0],dp[1][1]);
}