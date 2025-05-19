#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
bool CASE = false;
ll dp[2][N];
void solve (){
    int n,x;
    cin >> n >> x;
    vector<pii> book(n+1);
    for(int i = 1; i <= n; i++) cin >> book[i].st;
    for(int i = 1; i <= n; i++) cin >> book[i].nd;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[1][j] = dp[0][j];
            if(j >= book[i].st) dp[1][j] = max(dp[0][j-book[i].st]+book[i].nd,dp[1][j]);
        }
        for(int j = 1; j <= x; j++){
            dp[0][j] = dp[1][j];
        } 
    }
    cout << dp[0][x];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}