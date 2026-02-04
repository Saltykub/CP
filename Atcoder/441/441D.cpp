#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define piii pair<ll,pii> 
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<pii> adj[N];
void solve (){
    ll n,m,l,s,t;
    cin >> n >> m >> l >> s >> t;
    while(m--){
        ll u,v,c;
        cin >> u >> v >> c;
        adj[u].pb({v,c});
    }
    
    set<ll> mn[n+1][11], mx[n+1][11];
    queue<piii> pq;
    
    mn[1][0].insert(0);
    pq.push({0,{0,1}}); 
   // cout << "PASS";
    while(!pq.empty()){
        auto[cur,cntnode] = pq.front();
        auto[cnt,node] = cntnode;
        pq.pop();
        for(auto [v,w]:adj[node]){
            if(cnt + 1 > 10) continue;
            if(mn[v][cnt+1].count(cur+w) == 0){
                mn[v][cnt+1].insert(cur+w);
                pq.push({cur+w,{cnt+1,v}});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        auto it = mn[i][l].lower_bound(s);
        if(it == mn[i][l].end()) continue;
        if(*it > t) continue;
        cout << i << " ";
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