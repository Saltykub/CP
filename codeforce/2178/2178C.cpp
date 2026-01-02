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
void solve (){
    int n;
    cin >> n;
    vll v(n), pref(n,0), suff(n,0); // dp1 = max when i is first child , dp2 
    ll x = 0;
    ll ans = LLONG_MIN;
    for(auto &u:v) cin >> u;
    pref[0] = v[0];
    for(int i = 1; i < n; i++) pref[i]+=pref[i-1]+abs(v[i]);
    suff[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) suff[i] += suff[i+1] + v[i];
    for(int i = 0; i < n; i++){
        if(i == 0){
            ans = max(ans,-suff[1]);
        }
        else if(i == n-1){
            ans = max(pref[n-2],ans);
        }
        else {
            ans = max(ans,pref[i-1] - suff[i+1]);
        }
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