#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
const int N = 5e4 + 10;
ll dp[N][55];
void solve (){
    ll m,x,sm=0;
    cin >> m >> x;
    ll c[m+1], h[m+1];
    for(int i = 1; i <= m; i++){
        cin >> c[i] >> h[i];
        sm+=h[i];
    } 
    for(int i = 0; i <= sm; i++)for(int j = 0; j <= m; j++) dp[i][j] = LLONG_MAX;
    dp[0][0] = 0;
    ll mx = 0;
    for(int i = 0; i <= sm; i++){
        for(int j = 0; j <= m; j++){
            for(int k = j+1; k <= m; k++){
                if(dp[i][j] == LLONG_MAX) continue;
                if(dp[i][j] + c[k] <= x*(k-1)){
                    dp[i + h[k]][k] = min(dp[i+h[k]][k], dp[i][j] + c[k]); 
                }
            }
        }
    }
    for(int i = 0; i <= sm; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] != LLONG_MAX) {
                mx = i;
            }
        }
    }
    cout << mx << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}