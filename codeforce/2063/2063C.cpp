#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n;
    cin >> n;
    vector<ll> adj[n+5];
    vector<ll> mp(n+5,0);
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[u]++;
        mp[v]++;
    }
    priority_queue<pair<ll,ll>> pq;
    for(int i = 1; i <= n; i++) pq.push({mp[i],i});
    ll idx = pq.top().nd;
    set<int> s;
    for(int i = 1; i <= n; i++) if(mp[i] == pq.top().st) s.insert(i);
    for(int i = 1; i <= n; i++) {
        if(mp[i] == pq.top().st){
            ll cnt = 0;
            for(auto u:adj[i]){
                if(s.find(u) != s.end()) cnt++;
            }
            if(cnt+1 != s.size()) idx = i;
        }
    }
    ll ans = 0;
    ans+=pq.top().st;
    for(auto u:adj[idx]) mp[u]--;
    mp[idx] = 0;
    while(!pq.empty()) pq.pop();
    for(int i = 1; i <= n; i++) pq.push({mp[i],i});
    ans+=pq.top().st-1;
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}