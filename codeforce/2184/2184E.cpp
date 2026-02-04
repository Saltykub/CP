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
void solve (){
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    set<pii> s;
    vector<pair<int,pii>> adj;
    for(int i = 0; i < n-1; i++){
        adj.pb({abs(v[i]-v[i+1]),{i,i+1}});
    }
    sort(all(adj));
    reverse(all(adj));
    ll ans = 0;
    vll ret;
    int j = 0;
    for(int i = n-1; i > 0; i--){
        while(j < sz(adj) && adj[j].st >= i){
            auto [l,r] = adj[j].nd;
            auto lb = s.lower_bound({l,0});
            if(lb != s.begin()){
                lb--;
                auto target = *lb;
                ll sz = target.nd-target.st+1;
                if(target.nd == l){
                    s.erase(target);
                    ans -= sz*(sz-1)/2;
                    l = target.st;
                }
            }
            auto lb2 = s.lower_bound({r,0});
            if(lb2 != s.end()){
                auto target = *lb2;
                ll sz = target.nd-target.st+1;
                if(target.st == r){
                    s.erase(target);
                    ans -= sz*(sz-1)/2;
                    r = target.nd;
                }
            }
            ll sz = (r-l)+1;
            ans += sz*(sz-1)/2;
            s.insert({l,r});
            j++;
        }
        ret.pb(ans);
    }
    reverse(all(ret));
    for(auto u:ret) cout << u << " ";
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