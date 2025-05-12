#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> adj[N];
vector<ll> f(N,0);
ll mxposi = 0;
int cnt = 0;
void dfs(ll node){
    if(adj[node].size() == 0){
        f[node] = max(f[node],node);
        //cout << cnt++ << " ";
        return;
    }
    f[node] = node;
    for(auto u:adj[node]){
        if(!f[u])dfs(u);
        f[node] = max(f[node],f[u]);
    }
    if(adj[node].size() >= 2) mxposi = max(mxposi,f[node]);
    return;
}
void solve (){
   ll n,m;
   cin >> n >> m;
   ll mxsz = 0;
   mxposi = 0;
   for(int i = 0; i < n; i++){
        ll sz;
        cin >> sz;
        set<int> s;
        for(int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int use = false;
        ll mex1,mex2;
        for(ll j = 0; j <= sz+1; j++){
            if(!s.count(j)){
                if(!use){
                    mex1 = j;
                    mxposi = max(mex1,mxposi);
                    use = true;
                }
                else {
                    mex2 = j;
                    mxsz = max(mex2,mxsz);
                    break;
                }
            }
        }
        adj[mex1].pb(mex2);
   }
   for(int i = 0; i <= mxsz+1; i++){
        if(adj[i].size() == 0) continue;
        if(!f[i]) dfs(i);
   }
   ll ans = 0;
   for(ll i = 0; i <= min(mxsz+1,m); i++){
        ans += max({f[i],i,mxposi});
   }
   if(m > mxsz+1){
        ans += m*(m+1)/2 - (mxsz+2)*(mxsz+1)/2;
   }
   cout << ans << "\n";
   for(int i = 0; i <= mxsz+1; i++){
        adj[i].clear();
        f[i] = 0;
   }
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }

}