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
const int N = 3e5+10;
bool CASE = false;
vll adj[N];
vll dis(N,INT_MAX);
void solve (){
    ll n,m;
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
    }
    ll q;
    cin >> q;
    vector<pii> ans;
    for(ll i = 1; i <= q; i++){
        ll op,val;
        cin >> op >> val;
        if(op == 1){
            dis[val] = min(dis[val],i);
        }
        else {
            ans.pb({val,i});
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i = 1; i <= n; i++) if(dis[i] != INT_MAX) pq.push({dis[i],i});
    while(!pq.empty()){
        auto [cur,node] = pq.top();
        pq.pop();
        if(cur > dis[node]) continue;
        for(auto u:adj[node]){
            if(dis[u] > cur){
                dis[u] = cur;
                pq.push({dis[u],u});
            }
        }
    }
    for(auto [a,b]:ans){
        if(dis[a] <= b){
            cout << "Yes\n";
        }
        else cout << "No\n";
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