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
bool CASE = true;
vll adj[N];
vll c[N];
vll lv(N);
int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int ret;
    cin >> ret;
    return ret;
}
void fin(int a){
    cout << "! " << a << endl;
    return;
}
void solve (){
    int n;
    cin >> n;
    vll vis(n+1,0);
    vector<pii> edge;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        edge.pb({u,v});
    }
    for(auto [u,v]:edge){
        if(!vis[u] && !vis[v]){
            if(ask(u,v)){
                if(ask(u,u)){
                    fin(u);
                    return;
                }
                fin(v);
                return;
            }
            vis[u] = 1;
            vis[v] = 1;
        }
    }
    vll left;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) left.pb(i);
    }
    for(int i = 0; i+1 < sz(left); i+=2){
        if(ask(left[i],left[i+1])){
            if(ask(left[i],left[i])){
                fin(left[i]);
                return;
            }
            fin(left[i+1]);
            return;
        }
    }
    fin(left[sz(left)-1]);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}