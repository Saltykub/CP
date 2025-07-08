#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+10;
bool CASE = false;
void solve (){
   ll n,d;
   cin >> n >> d;
   vector<ll> cnt(N,0);
   vector<ll> a(n);
   for(auto &x:a){
        cin >> x;
        cnt[x]++;
   }
   ll ans = 0;
   if(d == 0){
      for(auto u:cnt){
        if(u) ans += u-1;
      }
      cout << ans;
   }
   else {
     for(int i = 0; i < d; i++){
        vector<ll> dp((N-i)/d+10,0);
        dp[0] = 0;
        dp[1] = cnt[i];
        if(i+d < N){
            dp[1] = min(dp[1],cnt[i+d]);
        }
        for(int j = 2; j <= (N-i)/d; j++){
            dp[j] = min(dp[j-1]+cnt[i+j*d],dp[j-2]+cnt[i+(j-1)*d]);
        }
        ans += dp[(N-i)/d];
     }
     cout << ans;
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