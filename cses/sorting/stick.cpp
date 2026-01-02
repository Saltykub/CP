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
    vll v(n);
    for(auto &u:v) cin >> u;
    sort(all(v));
    vll qs(n,0);
    qs[0] = v[0];
    for(int i = 1; i < n; i++) qs[i] = qs[i-1]+v[i];
    ll ans = qs[n-1] - (n-1)*v[0];
   // cout << ans << " ";
    for(int i = 1; i < n-1; i++){
        ll cal = v[i]*i - qs[i-1] + qs[n-1]-qs[i]-v[i]*(n-i-1);
        //cout << cal << " ";
        ans = min(ans,cal);
    }
    ans = min(ans,v[n-1]*n-qs[n-1]);
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