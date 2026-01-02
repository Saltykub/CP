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
    // dp[i][j] considering robot i and have diff = j
    int n;
    cin >> n;
    vector<pair<ll,pii>> v(n);
    for(int i = 0; i < n; i++){
        ll w,h,b;
        cin >> w >> h >> b;
        v[i].st = w;
        v[i].nd.st = h;
        v[i].nd.nd = b;
    }
    vector<ll> dp(500100,0);
    vector<ll> cnt(500100,0);
    dp[v[0].st+250000] = v[0].nd.nd;
    cnt[v[0].st+250000] = 1;
    dp[250000 - v[0].st] = v[0].nd.st;
    cnt[250000 - v[0].st] = 1;
    for(int i = 1; i < n; i++){
        auto [w, hb] = v[i];
        auto [h,b] = hb;
        vector<ll> ndp(500100,0);
        vector<ll> ncnt(500100,0);
        for(int j = 0; j <= 500000; j++){
            // add head 
            if(j+w <= 500000) {
                if(cnt[j+w] == i){
                    ndp[j] = max(ndp[j], dp[j+w] + h);
                    ncnt[j] = i+1;
                }
            }
            if(j-w >= 0){
                if(cnt[j-w] == i){
                    ndp[j] = max(ndp[j], dp[j-w] + b);
                    ncnt[j] = i+1;
                }
            }
        }
        swap(dp,ndp);
        swap(cnt,ncnt);
    }
    ll ans = 0;
    for(int j = 250000; j <= 500000; j++){
        if(cnt[j] != n) continue;
        ans = max(ans,dp[j]);
    }
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