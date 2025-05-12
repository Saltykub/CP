#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
vector<int> adj[N];
int dp[N][20],lv[N];
void dfs(int node,int p,int cur){
    dp[node][0]=p;lv[node]=cur;
    for(auto u:adj[node]){
        if(u!=p){
            dfs(u,node,cur+1);
        }
    }
}
int lca(int a,int b){
    if(lv[a]<lv[b])swap(a,b);
    for(int i=19;i>=0;i--) {
        if(lv[dp[a][i]]>=lv[b]){
            a=dp[a][i];
        }
    }
    
    if(a==b) return a;
    for(int i=19;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            //cout<<a<<" "<<b<<endl;
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];

}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    dfs(1,1,1);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        int LCA=lca(a,b);
        if(LCA==a||LCA==b){
            cout<<abs(lv[a]-lv[b]);
        }
        else cout<<lv[a]+lv[b]-2*lv[LCA];
        cout<<"\n";
    }

   
}