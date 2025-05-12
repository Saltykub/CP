#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
vector<int> adj[N];
int d[N][3];
int vis[N];
void dfs(int node,int cur,int i){
    if(vis[node]) return;
    vis[node]=1;
    d[node][i]=cur;
    for(auto u:adj[node])dfs(u,cur+1,i);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs(1,0,0);
    int mx=0,start=0,end=0;
    for(int i=1;i<=n;i++)if(mx<d[i][0]){start=i;mx=d[i][0];}
    memset(vis,0,sizeof vis);
    dfs(start,0,1);
    memset(vis,0,sizeof vis);
    mx=0;
    for(int i=1;i<=n;i++)if(mx<d[i][1]){end=i;mx=d[i][1];}
    dfs(end,0,2);
    for(int i=1;i<=n;i++)cout<<max(d[i][1],d[i][2])<<" ";
 
}