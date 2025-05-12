#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb emplace_back
using namespace std;
const int N = 1e6+3, mod = 1e9+7;
int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n+1,INT_MAX);
    dp[n] = 0;
    for(int i = n; i >= 0; i--){
        vector<int> v;
        ll temp = i;
        while(temp){
            v.push_back(temp%10);
            temp/=10;
        }
        for(auto u:v){
            dp[i-u] = min(dp[i-u],dp[i]+1);
        }
    }
    cout << dp[0];
}