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
const int N = 2e5+1;
bool CASE = false;
vll adj[N];
vll t(4*N); 
vll lz(4*N);
vll pa, depth, heavy, head, pos, vv;
int cur;

void add(int idx, int tl, int tr, int l, int val){
    if(tl == tr){
        t[idx] = val;
        return;
    }
    int tm = (tl+tr)/2;
    if (l <= tm)
        add(2*idx,tl,tm,l,val);
    else
        add(2*idx+1,tm+1,tr,l,val);
   
    t[idx] = max(t[2*idx],t[2*idx+1]);
}
ll query(int idx, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[idx];
    }
    int tm = (tl+tr)/2;
    return max(query(2*idx,tl,tm,l,min(r, tm)),
               query(2*idx+1,tm+1,tr,max(l, tm+1),r));
}

int dfs(int node){
    int sz = 1;
    int mx_sz = 0;
    for(auto u:adj[node]){
        if(u != pa[node]){
            pa[u] = node, depth[u] = depth[node]+1;
            int u_sz = dfs(u);
            sz += u_sz;
            if(u_sz > mx_sz){
                mx_sz = u_sz;
                heavy[node] = u;
            }
        }
    }
    return sz;
}
void hld(int node,int h){
    head[node] = h, pos[node] = cur++;
    // construct heavy path 
    if(heavy[node] != -1){
        hld(heavy[node],h);
    }
    for(auto u:adj[node]){
        // light edge 
        if(u != pa[node] && u != heavy[node]){
            hld(u,u);
        }
    }
}
void init(int n){
    pa = vll(n);
    depth = vll(n);
    heavy = vll(n,-1);
    head = vll(n);
    pos = vll(n);
    cur = 1;
    dfs(1);
    hld(1,1);
}

ll path(int a, int b){
   // cout << "PASS";
    ll ret = 0;
    for(;head[a] != head[b]; b = pa[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a,b);
        ll mx = query(1,1,N,pos[head[b]],pos[b]);
        ret = max(ret,mx);
    }
    if(depth[a] > depth[b]) swap(a,b);
    ll mx = query(1,1,N,pos[a],pos[b]);
    ret = max(ret,mx);
    return ret;
}

void solve (){
    int n,q;
    cin >> n >> q;
    vv = vll(n+1);
    for(int i = 1; i <= n; i++) cin >> vv[i];
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(n+1);
    for(int i = 1; i <= n; i++){
        //cout << pos[i] << " ";
        add(1,1,N,pos[i],vv[i]);
    }
   // cout << "pass";
    while(q--){
        ll op,a,b;
        cin >> op >> a >> b;
        if(op == 1){
            add(1,1,N,pos[a],b);
        }
        else {
            cout << path(a,b) << " ";
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