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
    int n;
    cin >> n;
    vector<vector<int>> d(n,vector<int>(6,0));
    vector<ll> p(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++) cin >> d[i][j];
        sort(d[i].begin(),d[i].end());
        mx = max(mx,d[i][0]);
    } 
    mi ans = 0;
    mi prob = 1;
    vector<pii> pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            if(d[i][j] <= mx) p[i]++;
            else pq.pb({d[i][j],i});
        }
        prob *= (mi)p[i];
        prob *= inv((mi)6);
    }
    mi prev = 0;
    sort(pq.begin(),pq.end());
    for(int i = 0; i < pq.size(); i++){
        auto [val,idx] = pq[i];
        if(val == mx){
            p[idx]++;
            prob *= (mi)p[idx] * inv((mi)(p[idx]-1)); 
        }
        else {
           ans += (prob-prev)*(mi)mx;
           prev = prob;
           p[idx]++;
           prob *= (mi)p[idx] * inv((mi)(p[idx]-1)); 
           mx = val;
        }
    }
    ans += (prob-prev)*(mi)mx;
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