#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
bool CASE = false;
void solve (){
    int n,p,k;
    cin >> n >> p >> k;
    vector<ll> aud(n);
    vector<vector<ll>> play;
    for(int i = 0; i < n; i++) cin >> aud[i];
    ll sm = accumulate(aud.begin(),aud.end(),0LL);
    for(int i = 0; i < n; i++){
        vector<ll> temp;
        for(int j = 0; j < p; j++){
            int s;
            cin >> s;
            s-=aud[i];
            temp.pb(s);
        }
        play.pb(temp);
    }
    vector<ll> dp(1<<p,LLONG_MIN);
    for(int i = 0; i < p; i++) dp[(1<<i)] = play[0][i];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        vector<ll> ndp(dp);
        for(int j = 0; j < (1<<p); j++){
            for(int kk = 0; kk < p; kk++){
                if((1<<kk) & j){
                    if(dp[j&(1<<kk)] == LLONG_MIN) continue;
                    ndp[j] = max(ndp[j],dp[j&(1<<kk)]+play[i][kk]);
                }
            }
        }
        dp = move(ndp);
    }
    cout << sm + dp[(1<<p)-1];
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}