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
    vector<int> h(n),dp(n,INT_MAX);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
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