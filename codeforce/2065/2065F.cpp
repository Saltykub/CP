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
    vector<int> a(n+1,0);
    vector<int> adj[n+1];
    vector<int> cnt(n+1,0);
    for(int i = 1; i <= n; i++){
         cin >> a[i];
         cnt[a[i]]++;
    }
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    string ans = "";
    for(int i = 0; i < n; i++) ans += '0';
    auto bfs = [&](int x){
       map<int,int> mp;
       for(auto u:adj[x]) mp[a[u]]++;
       mp[a[x]]++;
       for(auto [aa,b]:mp){
         if(b>=2) ans[aa-1] = '1';
       }
    };
    for(int i = 1; i <= n; i++){
        bfs(i);
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