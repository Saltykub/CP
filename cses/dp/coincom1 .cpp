#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb emplace_back
using namespace std;
const int N = 1e6+3, mod = 1e9+7;
int main(){
    ll n,x;
    cin >> n >> x;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(N,0);
    // dp[i] = number of solution to create i 
    for(int i = 0; i < n; i++) dp[c[i]] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(c[j] > i) continue;
            dp[i] += dp[i-c[j]];
            dp[i] %= mod;
        }
    }
    cout << dp[x];
    
}