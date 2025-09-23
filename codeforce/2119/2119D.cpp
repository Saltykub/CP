#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5010;
bool CASE = true;
ll dp[N][N]; // dp[i][j] = number of way after consider ith element and have jth zeros 
void solve (){
    ll n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j > 0) {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= m;
            }
            dp[i][j] += ((n-i+1)*(j+1)%m)*dp[i-1][j]%m;
            dp[i][j] %= m;
        }
    }
    ll sm = 0;
    for(int i = 0; i <= n; i++){
        sm += dp[n][i];
        sm%=m;
    }
    cout << sm << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}