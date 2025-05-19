#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,k;
    cin >> n >> k;
    vector<vector<ll>> dp(5001,vector<ll>(201,0)); // dp[i][k] = maximum number of two have ith number of five using k numbers 
    dp[0][0] = 1;
    for(int a = 0; a < n; a++){
        ll x, cnt5 = 0, cnt2 = 0;
        cin >> x;
        while(x%5 == 0){
            cnt5++;
            x/=5;
        }
        while(x%2 == 0){
            cnt2++;
            x/=2;
        }
        vector<vector<ll>> ndp(dp);
        for(int i = 0; i <= 5000; i++){
            for(int j = 1; j <= k; j++){
                ndp[i][j] = max(ndp[i][j],dp[i][j]);
                if(cnt5 <= i){
                    if(dp[i-cnt5][j-1]) ndp[i][j] = max(ndp[i][j],dp[i-cnt5][j-1] + cnt2);
                }
            }
        }
        dp = move(ndp);
    }
    ll ans = 0;
    for(ll i = 0; i <= 5000; i++){
        ans = max(ans,min(i,dp[i][k]-1));
    }
    cout << ans;

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}