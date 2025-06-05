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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    // initialize
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    // dp 
    for(int sz = 2; sz <= n; sz++){
        for(int i = 0; i < n-sz+1; i++){
            int j = i+sz-1;
            dp[i][j] = 1 + dp[i+1][j];
            if(arr[i] == arr[i+1]) dp[i][j] = min(dp[i][j], 1 + dp[i+2][j]);
            for(int k = i+2; k <= j; k++){
                if(arr[i] == arr[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
                }
            }
        }
    }
    cout << dp[0][n-1];
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}