#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 998244353;
bool CASE = false;
// mint 
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
vector<mi> fac(501);
mi choose[501][501];
mi qpow[501][501];
void precom(){
    fac[1] = 1;
    fac[0] = 1;
    for(int i = 2; i <= 500; i++) fac[i]  = fac[i-1] * i;
    for(int i = 0; i <= 500; i++){
        for(int j = 0; j <= 500; j++){
            mi ii = i;
            qpow[i][j] = pow(ii,j);
            if(i != 0 && i >= j){
                choose[i][j] = fac[i] * inv(fac[j]) * inv(fac[i-j]);
            }
        }
    }
}
// find invert fac use a lot of time 
// mi choose(ll n, ll r){
//     return fac[n] * inv(fac[r]) * inv(fac[n-r]);
// }
void solve (){
    ll n,k;
    cin >> n >> k;
    mi nn = n, kk = k;
    vector<vector<mi>> dp(n+1,vector<mi>(k+1,0)); // dp[i][j] = number of solution when there is ith knight and jth max health
    // base case 
    for(int j = 1; j <= k; j++){
        dp[2][j] = j;
    }
    ll cnt = 0;
    for(int i = 3; i <= n; i++){
        mi ii = i;
        for(int j = 1; j <= k; j++){
            mi jj = j;
            if(j < i) dp[i][j] = qpow[j][i];
            else {
                for(int l = 0; l <= i; l++){
                    if(i-l < 2 || j-i+1 < 1) break;
                    dp[i][j] += dp[i-l][j-i+1] * choose[i][l] * qpow[i-1][l];
                    cnt++;
                }
                dp[i][j] += qpow[i-1][i];
            }
        }
    }
    cout << (int) dp[n][k];   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    precom();
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}