#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 998244353;
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
vector<mi> fac(70);

void precom(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 60; i++){
        fac[i] = fac[i-1] * i;
    }
}
void solve (){
    ll n,k;
    cin >> n >> k;
    int digit = floor(log2(n))+1;
    if(k > digit){
        cout << 0 << "\n";
        return;
    }
    mi way = fac[digit-1] * inv(fac[k-1]) * inv(fac[digit-k]);
    mi sm = 0, two = 2, plus = 0;
    for(int i = 0; i <= digit-1; i++){
        sm += pow(two,i) * way;
    }
    ll left = k;
    for(int i = digit-1; i >= 0; i--){
        if((1LL<<i)&n) {
            left--;
            plus+=pow(two,i);
        }
        else {
            if(left > i+1) break;
            plus += pow(two,i);
            mi smm = 0;
            if(left == 1 || i == 0) way = 0;
            else  way = fac[i-1] * inv(fac[left-2]) * inv(fac[(i-1)-(left-2)]);
            for(int j = 0; j <= i-1; j++){
                smm += pow(two,j) * way;
            }
            if(left == 1) sm -= plus;
            else sm -= smm + plus*fac[i]*inv(fac[left-1])*inv(fac[i-left+1]);
            plus -= pow(two,i);
        }
        if(left == 0) break;
    }
    cout << (int) sm << "\n";
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