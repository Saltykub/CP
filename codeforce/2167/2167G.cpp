#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define vll vector<ll> 
#define vi vector<int>
using namespace std;
const int N = 1e4;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vll a(n), b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    vll dp(n,LLONG_MAX);
    vll v;
    for(auto u:a) v.pb(u);
    sort(v.begin(),v.end());
    unordered_map<ll,ll> mp(n);
    for(int i = 0; i < n; i++){
        mp[v[i]] = i;
        if(a[0] <= v[i]) dp[i] = 0;
        else dp[i] = b[0];
    }
    for(int i = 0; i < n; i++){
        a[i] = mp[a[i]];
        v[i] = mp[v[i]];
    }
    // min opreation that make the seq from 1 to i is monotonically less than j
    vll ndp(n,LLONG_MAX);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++) {
            ndp[j] = LLONG_MAX;
        }
        for(int j = 0; j < n; j++){
            if(a[i] == v[j]){
                ndp[j] = dp[a[i]];
            }
            else {
                ndp[j] = dp[v[j]] + b[i];
            }
        }
        swap(dp,ndp);
        for(int j = 1; j < n; j++){
            dp[j] = min(dp[j],dp[j-1]);
        }
    }
    cout << dp[n-1] << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}