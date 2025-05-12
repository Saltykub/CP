#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
// dp[i][j] = prop of  coin 0 to coin ith that have j coins as head 
void solve (){
    int n;
    cin >> n;
    vector<double> c(n+1);
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    for(int i = 1; i <= n; i++) cin >> c[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] += dp[i-1][j-1]*c[i];
            dp[i][j] += dp[i-1][j]*(1.0-c[i]);
        }
    } 
    double ans = 0;
    for(int i = (n+1)/2; i <= n; i++) ans += dp[n][i];
    printf("%.10f",ans);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}