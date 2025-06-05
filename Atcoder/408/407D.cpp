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
    string s;
    cin >> n >> s;
    vector<int> dp0(n+1,0), dp1(n+1,0);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            dp0[i+1]++;
            
        }
        else {
            dp1[i+1]++;
        }
        dp0[i+1] += dp0[i];
        dp1[i+1] += dp1[i];
    }
    vector<int> dp(n+1,INT_MAX);
    dp[n] = dp0[n];
    for(int i = n-1; i > 0; i--){
        int cur = dp0[i] - dp1[i] + dp1[n];
       // if(i == 3) cout << cur << " ";
        dp[i] = min(dp[i+1],cur);
        //cout << dp[i] << " ";
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int j = i+1;
        if(s[i] == '1'){
            ans = min(ans,dp1[j-1]-dp0[j-1] + dp[i+1]);
        }
    }
    if(dp1[n] == 0) ans = 0;
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}