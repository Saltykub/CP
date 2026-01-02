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
void solve (){
    ll n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    vll pref(n), suff(n);
    pref[0] = v[0];
    suff[n-1] = v[n-1];
    vll ret;
    for(int i = 1; i < n; i++){
        pref[i] = __gcd(pref[i-1],v[i]);
    }
    for(int i = n-2; i >= 0; i--){
        suff[i] = __gcd(suff[i+1],v[i]);
        ret.pb(min(pref[i],suff[i]));
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        ans+=min(pref[i],suff[i]);
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}