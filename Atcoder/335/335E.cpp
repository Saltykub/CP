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
const int N = 2e5+10;
bool CASE = false;
vll adj[N];
vll dis(N,0);
void solve (){
    int n,m;
    cin >> n >> m;
    vll v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    while(m--){
        int u,x;
        cin >> u >> x;
        if(v[x] >= v[u]) adj[u].pb(x);
        if(v[u] >= v[x]) adj[x].pb(u);
    }
    dis[1] = 1;
    
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}