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
ll bpow(int a,int b){
    if(b == 0) return 1;
    if(b % 2) return (bpow(a,b/2) * bpow(a,b/2))%MOD * a % MOD;
    return (bpow(a,b/2) * bpow(a,b/2))%MOD;
}
void solve (){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(auto &x:p) cin >> x;
    for(auto &x:q) cin >> x;
    int j = 0, j1 = 0;
    int mx = -1, mx1 = -1;
    for(int i = 0; i < n; i++){
        if(p[i] > mx){
            mx = p[i];
            j = i;
        }
        if(q[i] > mx1){
            mx1 = q[i];
            j1 = i;
        }
        ll ans;
        if(mx1 == mx) {
            if(q[i-j] > p[i-j1]) ans = (bpow(2,p[j]) + bpow(2,q[i-j]))%MOD;
            else ans = (bpow(2,p[i-j1])+bpow(2,q[j1])) % MOD;
        }
        else if(mx1 > mx) ans = (bpow(2,p[i-j1])+bpow(2,q[j1])) % MOD;
        else ans = (bpow(2,p[j]) + bpow(2,q[i-j]))%MOD;
        cout << ans << " ";
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}