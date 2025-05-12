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
void dfs(int node){
    if(vis[node])return;
    vis[node]=true;
    for(auto u:adj[node]){
        dfs(u);
        e[node]+=e[u];
    }   
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].pb(i);
    }
    for(int i=1;i<=n;i++){e[i]=1;vis[i]=false;}
    dfs(1);
    for(int i=1;i<=n;i++)cout<<e[i]-1<<" ";  
}