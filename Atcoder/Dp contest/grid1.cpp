#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
void solve (){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> tab(H+2,vector<char>(W+2,'.'));
    vector<vector<ll>> dp(H+2,vector<ll>(W+2,0));
    for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) cin >> tab[i][j];
    dp[1][1] = 1;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++){
            if(tab[i][j] == '#') continue;
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout << dp[H][W];

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}