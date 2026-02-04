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
    if(s[0] == '0' || s[n-1] == '0') {
        cout << -1 << "\n";
        return;
    }
    vll tmp;
    int cur = 1, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i]-'0' == cur){
            cnt++;
        }
        else {
            cur = s[i] -'0';
            tmp.pb(cnt);
            cnt = 1;
        }
    }
    tmp.pb(cnt);
    mi ret = 1;
    mi cnt2 = 0;
    ll ret2 =  1;
    bool use = false;
    for(int i = 0; i < sz(tmp); i++){
        if(i%2 == 0){
            for(int j = 1; j <= tmp[i]; j++) {
                ret *= 2;
                if(!use){
                    use = true;
                    continue;
                }
                ret2 *= 2;
                ret2 %= c;
            }
            cnt2+=tmp[i];
        }
        else {
            for(int j = 1; j <= tmp[i]; j++){
                ret *= cnt2;
                ret2 *= (int)cnt2;
                ret2 %= c;
                cnt2+=1;
            }
        }
    }
    ret *= inv((mi)2);
    if(ret2%c == 0){
        cout << -1 << "\n";
        return;
    }
    cout << (int) ret << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    // fac[0] = 1;
    // fac[1] = 1;
    // for(int i = 2; i < N; i++) fac[i] = fac[i-1]*i;
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}