#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;

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

void solve (){
    ll n,m;
    cin >> n >> m;
    vector<pair<pii,pii>> v(m);
    for(int i = 0; i < m; i++){
        auto [lr,pq] = v[i];
        auto [r,l] = lr;
        auto [p,q] = pq;
        cin >> l >> r >> p >> q;
    }
    sort(v.begin(),v.end());
    vector<mi> dp1(n+1,0), dp2(n+1,0); // dp1 = prob that has only 1 strip, dp2 = prob that has 0 strip
    dp1[0] = 1, dp2[0] = 1;
    for(auto [lr,pq]:v){
        auto [r,l] = lr;
        auto [p,q] = pq;
        mi prob = p*inv((mi)q);
        dp1[r] += dp1[l-1]*dp2[l-1]*prob;
        dp2[r]
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}