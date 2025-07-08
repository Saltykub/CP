#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int con(char c){
    if(c == 'J') return 0;
    return 1;
}
void solve (){
    int n;
    cin >> n;
    vector<string> v(2);
    cin >> v[0] >> v[1];
    vector<vector<int>> dp(n+2,vector<int>(3,0)); // dp[i][j] = min at position i with j ending type
    // fill base case 
    int curj = 0, cura = 0;
    (v[0][0] == 'J') ? curj++ : cura++;
    (v[1][0] == 'J') ? curj++ : cura++;
    (v[1][1] == 'J') ? curj++ : cura++;
    if(cura > curj) dp[1][1] = 1;
    curj = cura = 0;
    (v[0][0] == 'J') ? curj++ : cura++;
    (v[1][0] == 'J') ? curj++ : cura++;
    (v[0][1] == 'J') ? curj++ : cura++;
    if(cura > curj) dp[1][2] = 1; 
    dp[2][0] = ((con(v[0][2]) + con(v[0][1]) + con(v[0][0])) >= 2) +  ((con(v[1][2]) + con(v[1][1]) + con(v[1][0])) >= 2);
    for(int i = 2; i < n; i++){
        dp[i][0] = max({dp[i-1][1] + ((con(v[0][i-1]) + con(v[0][i]) + con(v[1][i])) >= 2), dp[i-1][2] + ((con(v[1][i-1]) + con(v[0][i]) + con(v[1][i])) >= 2),dp[i][0]});
        dp[i][1] = dp[i-2][0] + ((con(v[0][i-1]) + con(v[1][i-1]) + con(v[1][i])) >= 2);
        dp[i][2] = dp[i-2][0] + ((con(v[0][i-1]) + con(v[1][i-1]) + con(v[0][i])) >= 2);
        if(i-3 >= 0) {

            dp[i][0] = max(dp[i][0],dp[i-3][0] + ((con(v[0][i]) + con(v[0][i-1]) + con(v[0][i-2])) >= 2) +  ((con(v[1][i]) + con(v[1][i-1]) + con(v[1][i-2])) >= 2));
        }
        if(i-3 >= 1){
            dp[i][1] = max(dp[i][1],dp[i-3][1] + ((con(v[0][i-1]) + con(v[0][i-2]) + con(v[0][i-3])) >= 2) +  ((con(v[1][i]) + con(v[1][i-1]) + con(v[1][i-2])) >= 2));
            dp[i][2] = max(dp[i][2],dp[i-3][2] + ((con(v[0][i]) + con(v[0][i-1]) + con(v[0][i-2])) >= 2) +  ((con(v[1][i-1]) + con(v[1][i-2]) + con(v[1][i-3])) >= 2));
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < 3; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[n-1][0] << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}