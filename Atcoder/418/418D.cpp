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
    int n;
    string t;
    cin >> n >> t;
    vector<ll> dp0(n,0),dp1(n,0);
    if(t[0] == '1') dp1[0] = 1;
    else dp0[0] = 1;
    for(int i = 1; i < n; i++){
        if(t[i] == '0') {
            dp0[i] += dp1[i-1]+1;
            dp1[i] += dp0[i-1];
        }
        else {
            dp0[i] += dp0[i-1];
            dp1[i] += dp1[i-1]+1;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans+=dp1[i];
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}