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
const int MOD = 998244353;
template<int MOD, int RT> struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; } // primitive root
  int v; 
  explicit operator int() const { return v; } 
  mint():v(0) {}
  mint(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
  mint& operator+=(mint o) { 
    if ((v += o.v) >= MOD) v -= MOD; 
    return *this; }
  mint& operator-=(mint o) { 
    if ((v -= o.v) < 0) v += MOD; 
    return *this; }
  mint& operator*=(mint o) { 
    v = int((ll)v*o.v%MOD); return *this; }
 friend mint pow(mint a, ll p) { assert(p >= 0);
    return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
 friend mint inv(mint a) { assert(a.v != 0); return pow(a,MOD-2); }
 friend mint operator+(mint a, mint b) { return a += b; }
 friend mint operator-(mint a, mint b) { return a -= b; }
 friend mint operator*(mint a, mint b) { return a *= b; }
};

using mi = mint<MOD, 5>;
vll adj[N];
vll radj[N];
ll dp[N][32];
void solve (){
    int n,m;
    cin >> n >> m;
    vll a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[i].clear();
        radj[i].clear();
        for(int j = 1; j < 32; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    map<ll,map<ll,ll>> mp;
    map<ll,map<ll,vll>> mp2;

    for(int i = 1; i <= n; i++) {
        for(auto u:adj[i]){
            mp[u][a[i]+a[u]]++;
            mp2[u][a[i]+a[u]].pb(i);
        }
    }
    mi ans = 0;
    for(int i = 3; i < 32; i++){
        for(int j = 1; j <= n; j++){
            for(auto u:radj[j]){
                if(mp[u][a[j]]){
                    if(i == 3){
                        dp[j][i] += mp[u][a[j]];
                    }
                    else {
                        for(auto k:mp2[u][a[j]]){
                            if(a[k] < a[j]) dp[j][i] += dp[k][i-2];
                        }
                    }
                }
            }
            //if(dp[j][i] > 0 ) cout << j << " " << i << " " << dp[j][i] << "\n";
            ans += dp[j][i];
        }
    }
    ans += m;
    cout << (int) ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}