#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = true;
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
vector<mi> fac(2000001);

void precom(){
    fac[1] = 1;
    fac[0] = 1;
    for(int i = 2; i <= 2000000; i++) fac[i]  = fac[i-1] * i;
}
mi choose(ll n, ll r){
    return fac[n] * inv(fac[r]) * inv(fac[n-r]);
}
void solve (){
   ll n,m,k;
   cin >> n >> m >> k;
   mi ans = 0;
   vector<ll> v(n);
   for(int i = 0; i < n; i++) cin >> v[i];
   sort(v.begin(),v.end());
   for(int i = 0; i < n; i++){
        auto ub = upper_bound(v.begin(),v.end(),v[i]+k);
        if(ub == v.begin()) continue;
        int idx = ub - v.begin()-1;
        int length = idx - i + 1;
        if(length - 1 < m - 1) continue;
        ans += choose(length-1,m-1);
   }
   cout <<(int) ans << "\n";
   
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