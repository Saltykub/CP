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
    vector<vector<int>> dp(2,vector<int>(100001));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j <= 100000; j++){
            if(dp[0][j]) {
                if(j-x <= 100000){
                    dp[1][j+x] = 1;
                }
            }
            dp[1][j] = max(dp[1][j],dp[0][j]);
        }
        for(int j = 0; j <= 100000; j++){
            dp[0][j] = dp[1][j];
        }

    }
    vector<int> ans;
    for(int i = 1; i <= 100000; i++){
        if(dp[0][i]) ans.pb(i);
    }
    cout << ans.size() << "\n";
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