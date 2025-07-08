#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 3200;
ll dp[N][N];
bool CASE = false;
void solve (){
   ll n,h,m;
   cin >> n >> h >> m;
   vector<ll> a(n+1,0), b(n+1,0);
   for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
   for(int i = 1; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = INT_MAX;
   for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(dp[i-1][j] != INT_MAX) dp[i][j] = dp[i-1][j] + a[i];
            if(j - b[i] >= 0) {
                dp[i][j] = min(dp[i][j],dp[i-1][j-b[i]]);
            }
        }
   }
   ll ans = 0;
   for(int i = 1; i <= n; i++){
      //cout << dp[i][m] << " ";
      if(dp[i][m] <= h) ans = i;
   }
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