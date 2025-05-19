#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 998244353;
bool CASE = false;
void solve (){
    int q,k;
    cin >> q >> k;
    vector<int> dp(k+1);
    dp[0] = 1;
    while(q--){
        char op; int val;
        cin >> op >> val;
        if(op == '+'){
            for(int i = k; i >= val; i--) (dp[i] += dp[i-val]) %= MOD; 
        }
        else {
            for(int i = val; i <= k; i++) (dp[i] += MOD - dp[i-val]) %= MOD;
        }
        cout << dp[k] << "\n";
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