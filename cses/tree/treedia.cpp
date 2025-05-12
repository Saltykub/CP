#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int e[N];
bool vis[N];
vector<int> adj[N];
void dfs(int node,int cur){
    if(vis[node])return;
    vis[node]=true;
    e[node]=cur;
    for(auto u:adj[node]){
        dfs(u,cur+1);
    }   
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);

    }
    for(int i=1;i<=n;i++){vis[i]=false;}
    dfs(1,0);
    int mxidx=1,mx=0;
    for(int i=1;i<=n;i++){
        if(e[i]>mx){
            mx=e[i];mxidx=i;
        }
    }
    for(int i=1;i<=n;i++){e[i]=0;vis[i]=false;}
    dfs(mxidx,0);
    sort(e+1,e+n+1,greater<int>());cout<<e[1];
}