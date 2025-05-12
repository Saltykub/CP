#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
bool CASE = false;
ll dp[110][N]; // dp[i][j] = maxval consider item [i] with sum weight [j]
void solve (){
    int n, mxw; 
    cin >> n >> mxw;
    vector<ll> w(n+1),v(n+1);
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= mxw; j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i] >= 0) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][mxw];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}