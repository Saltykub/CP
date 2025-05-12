#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool CASE = false;
void solve (){  
   int n;
   cin >> n;
   vector<vector<int>> v(n,vector<int>(3)), dp(n,vector<int>(3,0));
   for(int i = 0; i < n ;i++)for(int j = 0; j < 3; j++) cin >> v[i][j];
   for(int i = 0; i < 3; i++) dp[0][i] = v[0][i];
   for(int i = 1; i < n; i++){
      for(int j = 0; j < 3; j++){
         for(int k = 0; k < 3; k++){
            if(j!=k) {
                dp[i][j] = max(dp[i-1][k]+v[i][j],dp[i][j]);
            }
         }
      }
   }
   cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    if(CASE) cin >> t;
    else t = 1;
    while(t--)
    {
        solve();
    }
}