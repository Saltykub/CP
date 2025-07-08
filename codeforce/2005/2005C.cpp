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
   int n,m;
   cin >> n >> m;
   vector<string> arr(n);
   vector<vector<ll>> dp(n+1,(vector<ll>(5,INT_MIN))); 
   dp[0][0] = 0;
   for(int i = 0; i < n; i++) cin >> arr[i];
   for(int i = 0; i < n; i++){
        for(int k = 0; k < 5; k++){
            dp[i+1][k] = max(dp[i][k],dp[i+1][k]);
            string temp = "narek";
            if(dp[i][k] == INT_MIN) continue;
            int cur = k,cal = 0;
            for(int j = 0; j < m; j++){
                bool ch = false;
                for(int c = 0; c < 5; c++) if(arr[i][j] == temp[c]) ch = true;
                if(ch){
                    if(arr[i][j] == temp[cur]){
                         cal ++;
                         cur ++;
                         cur%=5;
                    }
                    else {
                        cal --;
                    }
                }
            }
            
            dp[i+1][cur] = max(dp[i+1][cur],dp[i][k]+cal);
        }
   }
   ll ans = 0;
   for(int j = 0; j < 5; j++) ans = max(dp[n][j] - 2*j,ans);
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