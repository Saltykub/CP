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
    vector<vector<int>> dp(k+1,vector<int>(k+1,0)); // dp[i][j] = subset that has sum i and another subset that has sum j // we focuse when i + j = k
    dp[0][0] = 1;
    for(int l = 0; l < n; l++){
        int x;
        cin >> x;
        vector<vector<int>> ndp(dp);
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k-i; j++){
                if(i >= x) ndp[i][j] |= dp[i-x][j];
                if(j >= x) ndp[i][j] |= dp[i][j-x];
            }
        }
        dp = move(ndp);
    }
    vector<int> ans;
    for(int i = 0; i <= k; i++){
        if(dp[i][k-i]) ans.pb(i);
    } 
    cout << ans.size() << endl ;
    for(auto u:ans) cout << u << " ";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}