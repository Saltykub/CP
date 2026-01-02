#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<pii> adj[N];
ll start[N], ed[N];
ll dis[N];
int timer = 1;
ll t[2][4*N], lz [2][4*N];
void tour(int node, int cur){
    start[node] = timer++;
    for(auto u:adj[node]){
        tour(u.st,cur+u.nd);
        dis[u.st] = cur+u.nd;
    }
    ed[node] = timer;
}
void push(int idx, int s){
    t[s][2*idx] += lz[s][idx];
    t[s][2*idx+1] += lz[s][idx];
    lz[s][2*idx] += lz[s][idx];
    lz[s][2*idx+1] += lz[s][idx];
    lz[s][idx] = 0;
}
void add(int idx, int tl, int tr, int l, int r, int val, int s){
    if(l > r) return;
    if(tl == l && tr == r){
        t[s][idx] += val;
        lz[s][idx] += val;
        return;
    }
    push(idx,s);
    int tm = (tl+tr)/2;
    add(2*idx,tl,tm,l,min(r,tm),val,s);
    add(2*idx+1,tm+1,tr,max(l,tm+1),r,val,s);
    t[s][idx] = min(t[s][2*idx],t[s][2*idx+1]);
}
ll query(int idx, int tl, int tr, int l, int r, int s){
    if(l > r) return LLONG_MAX;
    if(tl == l && tr == r){
        return t[s][idx];
    }
    push(idx,s);
    int tm = (tl+tr)/2;
    return min(query(2*idx,tl,tm,l,min(r,tm),s),
               query(2*idx+1,tm+1,tr,max(l,tm+1),r,s));
}

void solve (){
    int n,q;
    cin >> n >> q;
    vector<vll> edge;
    edge.pb({0,0,0});
    vll back(n+1);
    for(int i = 1; i <= n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        edge.pb({u,v,w});
    }
    for(int i = n; i <= 2*n-2; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.pb({u,v,w});
        back[u] = w;
    }
    tour(1,0);
    for(int i = 1; i <= n; i++){
        add(1,1,n,start[i],start[i],dis[i],0);
        add(1,1,n,start[i],start[i],dis[i]+back[i],1);
    }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            ll e,w;
            cin >> e >> w;
            ll u = edge[e][0], v = edge[e][1], cur = edge[e][2];
            ll diff = w-cur;
            if(e <= n-1){
                edge[e][2] = w;
                add(1,1,n,start[v],ed[v]-1,diff,0);
                add(1,1,n,start[v],ed[v]-1,diff,1);
            }
            else {
                edge[e][2] = w;
                add(1,1,n,start[u],start[u],diff,1);
            }
        }
        else {
            int u,v;
            cin >> u >> v;
            if(ed[u]-1 >= start[v] && start[v] >= start[u]){
                cout << query(1,1,n,start[v],start[v],0) - query(1,1,n,start[u],start[u],0) << "\n";
            }
            else {
                cout << query(1,1,n,start[v],start[v],0) + query(1,1,n,start[u],ed[u]-1,1) - query(1,1,n,start[u],start[u],0) << "\n";
            }
        }
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}