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
    int n;
    cin >> n;
    vector<int> arr(n), dp(5001,INT_MAX);
    for(auto &x:arr) cin >> x;
    sort(arr.begin(),arr.end(),greater<int>());
    int g = arr[0];
    for(auto u:arr){
        dp[u] = 0;
        vector<int> ndp(dp);
        for(int i = 1; i <= 5000; i++){
            if(dp[i] == INT_MAX) continue;
            ndp[__gcd(i,u)] = min(dp[i]+1,ndp[__gcd(i,u)]);
        }
        g = __gcd(g,u);
        dp = move(ndp);
    }
    int ans = 0;
    for(auto u:arr) if(u != g) ans++;
    ans += dp[g]-1;
    if(dp[g] == 0) ans++;
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