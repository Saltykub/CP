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
mi mp[2000][2000];
void solve (){
    int n;
    int x = sqrt(N);
    cin >> n;
    vll v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<mi> dp(n+1,0);
    dp[1] = 1;
    if(v[1] <= x) mp[v[1]][1%v[1]] = 1;
    else {
        for(int j = 1 + v[1]; j <= n; j+=v[1]){
            dp[j]+=1;
        }
    }
    mi ret = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i] += mp[j][i%j];
        }
        if(v[i] <= x) mp[v[i]][i%v[i]] += dp[i];
        else {
            for(int j = i + v[i]; j <= n; j+=v[i]){
                dp[j]+=dp[i];
            }
        }
        ret += dp[i];
    }
    cout << (int) ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}