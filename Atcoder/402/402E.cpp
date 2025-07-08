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
    int n,x;
    cin >> n >> x;
    vector<int> s(n),c(n);
    vector<double> p(n);
    vector<vector<double>> dp((1<<n),vector<double>(x+1,0)); // dp[i][j] = max expected value when we solve problem in ith and has jth yen left
    for(int i = 0; i < n; i++){
        cin >> s[i] >> c[i] >> p[i];
        p[i]*=0.01;
    }
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < (1<<n); j++){
            for(int k = 0; k < n; k++){
                int ii = i-c[k];
                int jj = j|(1<<k);
                if(ii < 0 || jj == j) continue;
                double val = p[k]*(dp[jj][ii] + s[k]) + (1-p[k])*(dp[j][ii]);
                dp[j][i] = max(val,dp[j][i]);
            }
        }
    }
    cout << fixed << setprecision(10)<< dp[0][x];

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}