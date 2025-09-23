#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e4+10;
bool CASE = false;
ll dp[N][1005];
ll pref[N];
void solve (){
    int n;
    cin >> n;
    vector<pair<int,pii>> gift(n);
    for(int i = 0; i < n; i++) cin >> gift[i].st >> gift[i].nd.st >> gift[i].nd.nd;
    for(int j = 0; j <= 1000; j++) {
        if(gift[n-1].st >= j) dp[n-1][j] = j+gift[n-1].nd.st;
        else dp[n-1][j] = j-gift[n-1].nd.nd;
        dp[n-1][j] = max(dp[n-1][j],0LL);
    }
    for(int i = n-2; i >= 0; i--){
        auto [p,ab] = gift[i];
        auto [a,b] = ab;
        for(int j = 0; j <=1000; j++){
            if(p >= j){
                dp[i][j] = dp[i+1][j+a];
            }
            else dp[i][j] = dp[i+1][max(j-b,0LL)];
        }
    }
    pref[0] = gift[0].nd.nd;
    for(int i = 1; i < n; i++) pref[i] = pref[i-1]+gift[i].nd.nd;
    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        if(x <= 1000){
            cout << dp[0][x] << "\n";
        }
        else {
            auto it = lower_bound(pref,pref+n,x-500);
            if(it >= pref+n-1) cout << x-pref[n-1] << "\n";
            else cout << dp[it-pref+1][x-pref[it-pref]] << "\n";
        }
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