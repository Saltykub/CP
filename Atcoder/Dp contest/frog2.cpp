#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool CASE = false;
void solve (){  
    int n,k;
    cin >> n >> k;
    vector<int> h(n),dp(n,INT_MAX);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= min(i,k); j++){
            dp[i] = min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]);
        }
    }
    cout << dp[n-1];
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