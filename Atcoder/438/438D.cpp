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
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    vll a(n), b(n), c(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    for(auto &u:c) cin >> u;
    vll dp1(n,0), dp2(n,0), dp3(n,0);
    dp1[0] = a[0];
    for(int i = 1; i < n; i++){
        dp2[i] = max(dp2[i-1]+b[i],dp1[i-1]+b[i]);
        //cout << dp2[i] << " ";
        dp1[i] += dp1[i-1]+a[i];
    }
   // cout << "\n";
    dp3[1] = dp2[1];
    for(int i = 2; i < n; i++){
        dp3[i] = max(dp3[i-1]+c[i],dp2[i-1]+c[i]);
       // cout << dp3[i] << "\n";
    }
    cout << dp3[n-1];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}