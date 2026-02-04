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
mi fac[31];
mi cal[31][31];
void solve (){
    ll n,k;
    cin >> n >> k;
    k++;
    int cnt = 0;
    mi ans = 0;
    for(int i = 1; i <= 30; i++){
        if(pow(2,i) >= n) break;
        int bit = i+1;
        if(bit+bit-1 < k) continue;
        int target = max(0LL,k-bit);
        if(target <= bit-1){
            ans += cal[bit-1][target];
        }
    }
    if(1+log2(n) >= k) ans+=1;
    cout << (int) ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0] = 1;
    fac[1] = 1;
    for(ll i = 2; i <= 30; i++){
        fac[i] = fac[i-1]*i;
    }
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= i; j++){
            cal[i][j] += fac[i]*inv(fac[j])*inv(fac[i-j]);
        }
        for(int j = i-1; j >= 0; j--){
            cal[i][j] += cal[i][j+1];
        }
    }
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}