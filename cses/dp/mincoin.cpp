#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb emplace_back
using namespace std;
const int N = 1e6+3;
int main(){
    ll n,x;
    cin >> n >> x;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(N,N);
    for(int i = 0; i < n; i++) dp[c[i]] = 1;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(c[j] > i) continue;
            dp[i] = min(dp[i],dp[i-c[j]] + 1);
        }
       // cout << dp[i] << endl;
    }
    dp[x] == N ? cout << -1 : cout << dp[x];
}