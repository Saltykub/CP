#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
bool CASE = true;
vector<ll> dp(N,INT_MAX);
void solve (){
    int n;
    cin >> n;
    if(dp[n] == INT_MAX) cout << -1 << "\n";
    else cout << dp[n] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll mx = 500000;
    dp[1] = 1;
    dp[3] = 2;
    for(int i = 3; i <= mx; i+=2){
        dp[i+2] = min(dp[i+2],dp[i]+1);
        for(int j = 3; j <= i; j+=2){
            if(j*i > mx) break;
            dp[i*j] = min(dp[i*j],dp[i]+dp[j]-1LL);
        }
    }
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}