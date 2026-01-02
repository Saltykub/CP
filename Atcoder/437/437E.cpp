#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define tp tuple<ll,ll,ll> 
using namespace std;
const int N = 3e5+10;
bool CASE = false;
map<pii,int> trie;
ll nn[N];
vll v[N];
vll cnt[N];
vll ret;
int nxt = 0;
void add(int p, int val, int node){
    if(trie[{nn[p],val}]){
        v[trie[{nn[p],val}]].pb(node);
        nn[node] = trie[{nn[p],val}];
    }
    else {
        trie[{nn[p],val}] = ++nxt;
        cnt[nn[p]].pb(val);
        nn[node] = trie[{nn[p],val}];
        v[trie[{nn[p],val}]].pb(node);
    }
}
void dfs(int node){
    for(auto u:v[node]) ret.pb(u);
    sort(all(cnt[node]));
    for(auto u:cnt[node]){
        dfs(trie[{node,u}]);
    }
    
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) nn[i] = -1;
    for(int i = 0; i < n; i++){
        int p,val;
        cin >> p >> val;
        add(p,val,i+1);
    }
    //cout << "PASS";
    dfs(0);
    for(auto u:ret) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}