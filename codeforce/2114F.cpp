#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> prime;
void precom(){
    vector<int> ch(1e6+1,1);
    for(int i = 2; i <= 1000000; i++){
        if(ch[i]){
            prime.pb(i);
            for(int j = i+i; j <= 1000000; j+=i){
                ch[j] = 0;
            }
        }
    }
}
void solve (){
   ll x,y,k;
   cin >> x >> y >> k;
   ll gcd = __gcd(x,y);
   x/= gcd;
   y/= gcd;
   vector<int> dp(x+1,INT_MAX);
   dp[1] = 0;
   ll ans = 0;
   // O(factor n* )
   for(int i = 1; i <= x; i++){
        if(x%i) continue;
        for(int j = 2; i*j <= x && j <= k; j++){
           if(dp[i] == INT_MAX) continue;
           dp[i*j] = min(dp[i*j],dp[i]+1);
        }
   }
   ans += dp[x];
   if(dp[x] == INT_MAX) {
     cout << -1 << "\n";
     return;
   }
   dp.resize(y+1,INT_MAX);
   dp[1] = 0;
    for(int i = 1; i <= y; i++){
        if(y%i) continue;
        for(int j = 2; i*j <= y && j <= k; j++){
           if(dp[i] == INT_MAX) continue;
           dp[i*j] = min(dp[i*j],dp[i]+1);  
        }
   }
   if(dp[y] == INT_MAX) {
    cout << -1 << "\n";
    return;
   }
   cout << ans + dp[y] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    precom();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}