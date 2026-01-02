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
ll p = 69420;
const int MOD = 1e9+9;
void solve (){
    string s;
    cin >> s;
    int n = s.size();
    
    vll bpow(n);
    vll pref(n+1,0);
    bpow[0] = 1;
    for(int i = 1; i < n; i++) bpow[i] = p*bpow[i-1] % MOD;
    for(int i = 1; i <= n; i++) pref[i] = (pref[i-1]*p + s[i-1]) % MOD;

    function<ll(int,int)> hash = [&](int l, int r){
        ll ret = pref[r+1] - (pref[l]*bpow[r-l+1]%MOD)%MOD;
        ret += MOD;
        ret %= MOD;
        return ret;
    };

    for(int i = 0; i < n; i++){
        int cur = 0;
        bool can = true;
        while(cur < n){
            int len = min(i+1,n-cur);
            can &= hash(0,len-1) == hash(cur,cur+len-1);
            cur += len;
        }
        if(can) cout << i+1 << " ";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}