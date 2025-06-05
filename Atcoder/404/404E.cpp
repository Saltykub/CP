#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    n--;
    vector<int> a(n+1,0), c(n+1,0), dp(n+1,INT_MAX), p(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) p[i] = i;
    int ans = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i-1; j >= i-c[i]; j--){
            if(dp[i] > dp[j]+1){
                p[i] = j;
                dp[i] = dp[j]+1;
            }
        }
        if(a[i]){
            ans += dp[i];
            dp[i] = 0;
            int nxt = i;
            while(dp[p[nxt]] != 0){
                dp[p[nxt]] = 0;
                nxt = p[nxt];
            }
        }
    }
    cout << ans;
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}