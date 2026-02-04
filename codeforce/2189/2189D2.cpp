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
const int MOD = 1e9+7;
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
int m = 3;
using mi = mint<MOD, 5>;

void solve (){
    ll n,c;
    cin >> n >> c;
    string s;
    cin >> s;   
    vll tmp;
    int cnt = 0;
    if(s[0] == '0' || s[n-1] == '0') {
        cout << -1 << "\n";
        return;
    }
    if(s[1] == '?') s[1] = '0';
    s[0] = '1';
    s[n-1] = '1';
    mi ans = 2;
    ll cal = 2;
    for(ll i = 1; i < n-1; i++){
        if(s[i] == '0'){
            ans *= i;
            cal *= i;
            cal %= c;
        }
        else if(s[i] == '1'){
            ans *= 2;
            cal *= 2;
            cal %= c;
        }
        else {
            if(i%2){
                tmp.pb(i);
            }
            else {
                ans *= 2;
                cal *= 2;
                cal %= c;
            }
        }
    }
    cal %= c;
    reverse(all(tmp));
    for(auto u:tmp){
        if(cal*2%c == 0){
            cal *= u;
            cal %= c;
            ans *= u;
        }
        else {
            ans *= 2;
            cal *= 2;
            cal %= c;
        }
    }
    if(cal%c == 0){
        cout << -1 << "\n";
    }
    else cout << (int) ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}