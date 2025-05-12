#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N = 2e5+5;
ll arr[N],sz[N],vis[N],fw[N],idx[N],arr2[N];
map<int,int> mp;
ll curidx = 1;
vector<int> adj[N];
pii q[N];
void dfs(int node,int p){
    if(vis[node]) return;
    vis[node] = 1;
    idx[node] = curidx;
    curidx ++;
    for(auto u:adj[node]){
        if(u!=p){
            dfs(u,node);
            sz[node]+=sz[u];
        }
    }
}
void add(int i,int val){
    for(; i < N; i += (i&-i)) fw[i] += val;
}
ll qs(int i){
    ll ret=0;
    for(;i>0;i-=(i&-i)){
        ret+=fw[i];
    }
    return ret;
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){cin >> arr[i]; sz[i] = 1;}
    for(int i=1; i < n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    for(int i = 1; i <= n; i++){
        q[idx[i]].st = idx[i]+sz[i]-1;
        q[idx[i]].nd = i;
        arr2[idx[i]] = arr[i];
    }
    for(int i = n; i > 0; i--){
        //cout << arr2[i] << " ";
        if(mp[arr2[i]])add(mp[arr2[i]],-1);
        add(i,1);
        mp[arr2[i]] = i;
        arr[q[i].nd] = qs(q[i].st); 
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] <<" ";
    }

}