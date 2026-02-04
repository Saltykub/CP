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
const int N = 5e3+10;
bool CASE = false;
int qs[N][N];
ll dp[N][N];
void solve (){
    int n;
    cin >> n;
    char tab[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tab[i][j];
        }
    }
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            if(tab[i][j] == '#') qs[i][j]++;
            qs[i][j] += qs[i-1][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = qs[n-j][i] + j - (qs[n][i]-qs[n-j][i]) + dp[i-1][j];
            if(j > 0) dp[i][j] = min(dp[i][j],dp[i][j-1]);
        }
        dp[i][n] = n-qs[n][i] + dp[i-1][n];
        dp[i][n] = min(dp[i][n],dp[i][n-1]);
    }
    ll mn = INT_MAX;
    for(int i = 0; i <= n; i++){
        mn = min(dp[n][i],mn);
    }
    cout << mn;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}