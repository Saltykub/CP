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
    ll n,p;
    cin >> n >> p;
    vector<ll> a(n);
    map<ll,vector<ll>> mp;
    vector<bool> vis(n,false);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    ll ans = (n-1)*p;
    for(auto v:mp){
        if(v.st >= p) break;
        for(auto u:v.nd){
            for(int i = u+1; i < n; i++){
                 if(vis[i]) break;
                 if(a[i]%a[u] == 0) {
                    ans -= p;
                    ans += v.st;
                    vis[i] = true;
                 }
                 else break;
            }
            for(int i = u; i > 0; i--){
                 if(vis[i]) break;
                 if(a[i-1]%a[u] == 0) {
                    ans -= p;
                    ans += v.st;
                    vis[i] = true;
                 }
                 else break;
            }
        }
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