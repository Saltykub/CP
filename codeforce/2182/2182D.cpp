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
mi fac[60];
void precom(){
    fac[1] = 1;
    fac[0] = 1;
    for(int i = 2; i < 60; i++){
        fac[i] = fac[i-1]*i;
    }
}
void solve (){
    int n;
    cin >> n;
    vll v(n+1);
    ll sm = 0;
    for(auto &u:v) cin >> u;
    for(auto u:v){
        sm += u;
    }
    ll left = 0, round = 0;
    round = sm/n;
    left = sm%n;
    ll tleft = left;
    for(int i = 1; i <= n; i++){
        if(v[i] < round) {
            v[0] -= round-v[i];
            v[i] = round;
        }
        else if(v[i] > round){
            left--;
        }
    }
    if(v[0] < 0){
        cout << 0 << "\n";
    }
    else {
        if(v[0] != left){
            cout << 0 << "\n";
        }
        else {
            int can = 0;
            for(int i = 1; i <= n; i++){
                if(v[i] == round) can++;
            }
           mi ans = fac[can]*inv(fac[left])*inv(fac[can-left]) * fac[n-tleft] * fac[tleft];
           cout << (int) ans << "\n";
        }
    }
    
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