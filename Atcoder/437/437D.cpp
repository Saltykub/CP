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
    int n,m;
    cin >> n >> m;
    vll a(n),b(m),qsa(n),qsb(m);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    sort(all(a));
    sort(all(b));
    for(int i = 0; i < n; i++){
        qsa[i] += a[i];
        if(i > 0) qsa[i] += qsa[i-1];
    }
    for(int i = 0; i < m; i++){
        qsb[i] += b[i];
        if(i > 0) qsb[i] += qsb[i-1];
    }
    mi ret = 0;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(all(b),a[i]);
        if(it == b.end()){
            ret += m*a[i];
            ret -= qsb[m-1];
        }
        else {
            int idx = it-b.begin();
            ret += (idx)*a[i];
            ret -= (m-idx)*a[i];
            ret += qsb[m-1];
            if(idx > 0) ret -= 2*qsb[idx-1];
        }
    }
    cout << (int) ret << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}