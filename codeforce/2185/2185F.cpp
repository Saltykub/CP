#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,q;
    cin >> n >> q;
    int nn = pow(2,n);
    vll v(nn);
    for(auto &u:v) cin >> u;
    ll dp[nn][n];
    for(int i = 0; i < nn; i++){
        dp[i][0] = v[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < nn; j+=pow(2,i-1)){
            ll idx = j+pow(2,i-1);
            dp[j][i] = dp[j][i-1]^dp[idx][i-1];
        }
    }
    while(q--){
        ll idx,val;
        cin >> idx >> val;
        idx--;
        int ans = 0;
        //cout << idx << ' ';
        for(int i = 0; i < n; i++){
            ll p = pow(2,i);
            ll pp = p*2;
            if(idx%pp){
                if(dp[idx-p][i] >= val){
                    ans += p;
                }
                val^=dp[idx-p][i];
                idx = idx-p;
            }
            else {
                //cout << dp[idx+p][i];
                if(dp[idx+p][i] > val){
                    ans += p;
                }
                val^=dp[idx+p][i];
            }
            //cout << idx << " " << val << "\n";
        }
        cout << ans << "\n";
    }
    //cout << dp[0][0];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}