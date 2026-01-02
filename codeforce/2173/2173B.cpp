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
    int n;
    cin >> n;
    vll a(n), b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    vll dp1(n,INT_MIN), dp2(n,INT_MAX);
    dp1[0] = max(-a[0],b[0]);
    dp2[0] = min(-a[0],b[0]);
    for(int i = 1; i < n; i++){
        dp1[i] = max(dp1[i-1]-a[i],b[i]-dp2[i-1]);
        dp2[i] = min(dp2[i-1]-a[i],b[i]-dp1[i-1]);
    }
    cout << dp1[n-1] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}