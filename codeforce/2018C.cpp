#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
bool CASE = true;
vector<int> lv(N,0), mxlv(N,0);
vector<int> adj[N];
void dfs(int node,int p){
    mxlv[node] = lv[node];
    for(auto u:adj[node]){
        if(u != p) {
            lv[u] = lv[node]+1;
            dfs(u,node);
            mxlv[node] = max(mxlv[node],mxlv[u]);
        }
    }
    return;
}
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
        lv[i] = 0;
        mxlv[i] = 0;
    }
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    lv[1] = 1;
    dfs(1,1);
    vector<int> qs(n+5,0), cnt(n+5,0);
    for(int i = 1; i <= n; i++){
        qs[mxlv[i]] ++;
        cnt[lv[i]]++;
    }
    for(int i = 2; i <= n; i++) {
        qs[i] += qs[i-1];
        cnt[i] += cnt[i-1];
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        ans = min(ans,qs[i-1] + cnt[n]-cnt[i]);
    }
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