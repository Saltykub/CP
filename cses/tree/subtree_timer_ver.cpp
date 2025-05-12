#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N = 2e5+5;
ll arr[N],in[N],out[N],vis[N],fw[N];
vector<int> adj[N];
int timer = 0;
void tour(int node){
    in[node] = ++timer;
    for(auto u:adj[node])tour(u);
    out[node] = timer;
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
    int n,q;
    cin >> n >> q;
    for(int i=1; i<=n;i++){cin >> arr[i]; sz[i] = 1;}
    for(int i=1; i < n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    tour(1);
    for(int i=1;i<=n;i++){
        add(in[i],arr[i]);
    }
    while(q--){
        int o;cin >> o;
        if( o == 1){
            int s, val;
            cin >> s >> val;
            int pos = idx[s];
            add(pos,-arr[s]);
            add(pos,val);
            arr[s] = val;
        }
        else {
            int s;
            cin >> s;
            int pos = idx[s];
            cout << qs(pos+sz[s]-1)-qs(pos-1)<<"\n";

        }
    }

}