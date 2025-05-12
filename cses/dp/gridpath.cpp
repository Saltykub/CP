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
    vector<vector<char>> tab (n,vector<char>(n));
    vector<vector<ll>> dp (n,vector<ll>(n,0));
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) cin >> tab[i][j];
    if(tab[0][0] != '*') dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(tab[i][j] == '*') continue;
            if(i-1 >= 0 && tab[i-1][j] != '*') dp[i][j] += dp[i-1][j];
            if(j-1 >= 0 && tab[i][j-1] != '*') dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1];
}