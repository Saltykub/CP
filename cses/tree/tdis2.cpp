#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
vector<int> adj[N];
ll sz[N],ans[N],n;
void dfs(int node,int cur,int p){
    ans[1]+=cur;
    sz[node]=1;
    for(auto u:adj[node]){
        if(u!=p){
            dfs(u,cur+1,node);
            sz[node]+=sz[u];
        }
    }
}
void dfs2(int node,int p){
    for(auto u:adj[node]){
        if(u!=p){
            ans[u]=ans[node]+n-2*sz[u];
            dfs2(u,node);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs(1,0,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}