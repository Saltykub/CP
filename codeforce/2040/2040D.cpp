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
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> ans(n+1);
    ans[1] = 2;
    int fr = 4 , bk = 2*n;
    queue<pii> q;
    q.push({1,0});
    while(!q.empty()){
        auto [node,lv] = q.front();
        q.pop();
        lv++;
        for(auto u:adj[node]){
            if(!ans[u]){
                if(lv%2){
                   ans[u] = bk;
                   bk-=2;
                   if(abs(ans[u]-ans[node]) == 2) ans[u] = ans[node]-1; 
                   q.push({u,lv});
                }
                else {
                    ans[u] = fr;
                    fr += 2;
                    if(abs(ans[u]-ans[node]) == 2) ans[u] = ans[node]-1; 
                    q.push({u,lv});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}