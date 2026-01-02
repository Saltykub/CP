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
const int MxN = 1e7+10;
const int MOD = 1e6+3;
bool CASE = true;

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
vector<mi> fac(MxN);
void precom(){
    fac[0] = 1;
    for(int i = 1; i < MxN; i++){
        fac[i] = fac[i-1]*i;
    }
}
void solve (){
    ll n;
    cin >> n;
    vll a(n), b(n);
    ll mn = INT_MAX;
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    for(int i = 0; i < n; i++){
        ll tmp = a[i];
        for(ll j = 1; j <= 30; j++){
            tmp *= 2;
            if(tmp > b[i]){
                mn = min(mn,j-1);
                break;
            }
        }
    }
    ll cnt = mn;
    mi ret = 1;
    for(int j = mn; j >= 0; j--){
        ll add = 0;
        vll cadd;
        for(int i = 0; i < n; i++){
            ll cal = (b[i]/(pow(2,j)))-a[i];
            cnt += cal;
            add += cal;
            cadd.pb(cal);
            a[i]+=cal;
            a[i]*=2;
        }
        mi c = 0;
        if(add <= MOD) c = fac[add];
        for(auto u:cadd){
            c *= inv(fac[u]);
        }
        ret *= c;
        
    }
   
    cout << cnt << " " << (int) ret << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    precom();
    while(t--){   
        solve();
    }
}