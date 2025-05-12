#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> ans(N,0), succ(N), adj[N];
void dfs(int node,int val){
    if(ans[node]) return;
    ans[node] = val;
    for(auto u:adj[node]){
        dfs(u,val+1);
    }
}
void floy(int node){
    int f = succ[succ[node]], s = succ[node];
    while(f!=s){
        f = succ[succ[f]];
        s = succ[s];
    }
    s = node;
    while(f!=s){
        f = succ[f];
        s = succ[s];
    }
    vector<int> cycle;
    cycle.pb(s);
    int c = s;
    s = succ[s];
    while(s != c){
        cycle.pb(s);
        s = succ[s];
    }
    for(auto u:cycle) ans[u] = cycle.size();
    for(auto u:adj[c]){
        dfs(u,ans[c]+1);
    }
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> succ[i];
        adj[succ[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
       if(!ans[i])floy(i);
       cout << ans[i] << " ";
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