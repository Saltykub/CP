#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<vector<int>> dp(5000,vector<int>(5000,0));
void solve (){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for(int size = 2; size <= s.size(); size++){
        for(int i = 0; i < s.size()-size+1; i++){
            int j = i+size-1;
            if(size == 2){
                dp[i][j] = 2 ;
                if(s[i] == s[j]) {
                    dp[i][j]++;
                }
            }
            else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                if(s[i] == s[j]){
                   if(size == 3){
                      dp[i][j]++;
                   }
                   else if(size == 4){
                      if(dp[i+1][j-1] == 3) dp[i][j] ++;
                   }
                   else {
                     if(dp[i+1][j-1] == dp[i+2][j-1] + dp[i+1][j-2] - dp[i+2][j-2] + 1 ) dp[i][j] ++;
                   }
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << dp[l][r] << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}