#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;

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
vector<vector<mi>> choose(501,vector<mi>(501,0));
vector<mi> fac(501);
mi dp[501][501];
void precom(){
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 500; i++) fac[i] = fac[i-1] * i;
    choose[0][0] = 1;
    for(int i = 0; i <= 500; i++){
        for(int j = 0; j <= i; j++){
            choose[i][j] = fac[i] * inv(fac[j]) * inv(fac[i-j]);
        }
    }
}
void solve (){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i+1 <= n; ++i) dp[i+1][i] = 1;
    for(int i = n-1; i >= 0; --i){
        for(int j = i+1; j < n; j+= 2){
            for(int k = i+1; k <= j; k+= 2){
                if(s[i] == s[k]){
                    dp[i][j] += dp[i+1][k-1] * dp[k+1][j] * choose[(j-i+1)/2][(k-i+1)/2];
                }
            }
        }
    }
    cout << (int) dp[0][n-1]; 
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    precom();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}