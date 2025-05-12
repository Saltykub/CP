#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) cin >> v[i];
    int dp[n+1][2]; // dp[i][j] = min skip point that use to defeat ith monster ending with 0 (friend) or 1 (you)
    for(int i = 0; i <= n; i++) dp[i][1] = dp[i][0] = 10000000;
    dp[0][0] = v[0];
    if(n > 1) dp[1][0] = v[0] + v[1];
    for(int i = 1; i < n; i++){
        if(i > 1) dp[i][0] = dp[i-1][1] + v[i];
        dp[i][1] = dp[i-1][0];
        if(i > 1){
            dp[i][0] = min(dp[i-2][1] + v[i] + v[i-1],dp[i][0]);
            dp[i][1] = min(dp[i-2][0],dp[i][1]);
        }
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}