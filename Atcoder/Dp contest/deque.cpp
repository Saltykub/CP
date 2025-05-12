#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<vector<ll>> dp(3005,vector<ll>(3005,0));
vector<ll> a(3005,0);
ll cal(int i,int j){
    if(dp[i][j]) return dp[i][j];
    if(i == j) return dp[i][j] = a[i];
    return dp[i][j] = max(a[i]-cal(i+1,j),a[j]-cal(i,j-1));
}
void solve (){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << cal(1,n);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}