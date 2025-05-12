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
    vector<int> dp(x+1,0);
    sort(c,c+n);
    // dp[i] = number of distinct solution that create i;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = c[i]; j <= x; j++){
            dp[j] = (dp[j] + dp[j-c[i]])%mod;
        }
    }
    cout << dp[x];
    
}