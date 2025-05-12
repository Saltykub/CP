#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+10;
vector<int> adj[N];
vector<int> bcnt(N),c(N),pa(N);
void dfs(int node,int p){
    for(auto u:adj[node]){
        if(u == p) continue;
        if(c[u] == 1) bcnt[node]++;
        dfs(u,node);
        pa[u] = node;
    }
    return;
}
void solve(){
  int n,q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> c[i];
  for(int i = 0; i < n-1; i++){
     int u,v;
     cin >> u >> v;
     adj[u].pb(v);
     adj[v].pb(u);
  }
  dfs(1,1);
  pa[1] = 0;
  c[0] = 0;
  int curb = 0,one = 0, two = 0, more = 0;
  set<int> s;
  for(int i = 1; i <= n; i++){
    if(c[i]) {
        curb ++;
        if(bcnt[i] == 1) one ++;
        if(bcnt[i] == 2) {two ++;s.insert(i);}
        if(bcnt[i] > 2) more ++;
    } 
  }
  
  while(q--){
     int x; cin >> x;
    
     if(c[x]){
        c[x] = 0;
        curb--;
        int p = pa[x];
        if(bcnt[x] == 1) one --;
        if(bcnt[x] == 2){s.erase(x); two --;}
        if(bcnt[x] > 2) more --;
        if(x != 1) {
        bcnt[p]--;
        if(c[p]){
            if(bcnt[p] == 0) one--;
            if(bcnt[p] == 1) {one++;two--;s.erase(p);}
            if(bcnt[p] == 2) {two++;more--;s.insert(p);}
          }
        }
     }
     else {
        c[x] = 1;
        int p = pa[x];
        curb++;
        if(bcnt[x] == 1) one ++;
        if(bcnt[x] == 2) {two ++;s.insert(x);}
        if(bcnt[x] > 2) more ++;
        if(x != 1){
        bcnt[p]++;
        if(c[p]){
            if(bcnt[p] == 1) one ++;
            if(bcnt[p] == 2) {two ++;one--;s.insert(p);}
            if(bcnt[p] == 3) {more ++;two--;s.erase(p);}
        }
        }
     }
     bool can = true;
     if(more) can = false;
     else if(two > 1 || (two == 1 && c[pa[*s.begin()]])) {
        can = false;
     } 
     else if(one + 2*two != curb-1) can = false;
     can ? cout << "Yes\n" : cout << "No\n";
  }
  for(int i = 0; i <= n; i++) {
    adj[i].clear();
    bcnt[i] = 0;
    c[i] = 0;
    pa[i] = 0;
  }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}