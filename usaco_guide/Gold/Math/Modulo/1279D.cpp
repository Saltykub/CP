#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
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
using mi = mint<(int)998244353, 5>;

void solve (){
   int n;
   cin >> n;
   mi nn = n;
   vector<mi> gift(1000001,0);
   vector<vector<int>> child;
   for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> temp;
        while(k--) {
            int x; cin >> x;
            gift[x]+=1;
            temp.pb(x);
        }
        child.pb(temp);
   }
   mi ans = 0;
   for(auto c:child){
    mi sz = c.size();
     for(auto gi:c){
        ans += (inv(nn) * inv(sz)) * (gift[gi] * inv(nn));
     }
   }
   cout << (int) ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}