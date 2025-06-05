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
    string a,b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX)); // dp[i][j] minimum operation that make string a from 1 to ith equal to string b from 1 to jth
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); // delete a[i];
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); // add b[j] t- a[i];
            if(i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
        }
    }
    cout << dp[n][m];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}