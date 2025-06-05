#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
ll bpow(ll a,ll b, ll m){
    if(b == 0) return 1;
    if(b%2){
        return ((bpow(a,b/2,m) * bpow(a,b/2,m)) % m * a)%m;
    }
    return (bpow(a,b/2,m) * bpow(a,b/2,m)) % m;
}
ll cal(string a, int m, int d){

    vector<vector<ll>> dp(m,vector<ll>(2,0)); // dp[j][k] = the number of way that can construct array length ith with mod j and it is less than prefix or not
    for(int i = 0; i <= a[0]-'0'; i++){
        if(i == d) continue;
        dp[i%m][(i < a[0]-'0')]++;
    }
    for(int i = 1; i < a.size(); i++){
        int c = a[i]-'0';
        vector<vector<ll>> ndp(m,vector<ll>(2,0));
        for(int j = 0; j < m; j++){
            // add d
            if(i%2){
                int idx = (10*j + d)%m;
               // cout << dp[j][0] << " ";
                (ndp[idx][1] += dp[j][1]) %= MOD;
                if(c > d){
                    (ndp[idx][1] += dp[j][0]) %= MOD;
                }
                else if( c == d){
                    (ndp[idx][0] += dp[j][0]) %= MOD;
                }
            }
            // add other except d
            else {
                for(int k = 0; k <= 9; k++){
                    if(k == d) continue; 
                    int idx = (10*j + k)%m;
                    (ndp[idx][1] += dp[j][1]) %= MOD;
                    if(c > k){
                        (ndp[idx][1] += dp[j][0]) %= MOD;
                    }
                    else if(c == k){
                        (ndp[idx][0] += dp[j][0]) %= MOD;
                    }
                }
            }
        }
        dp = move(ndp);
    }
    return (dp[0][1] + dp[0][0]) % MOD;
}
ll check(string a, int m, int d){
    ll sm = 0;
    for(int i = 0; i < a.size(); i++){
        int c = a[i] - '0';
        if(i%2 && c!=d) return 0;
        else if(!(i%2) && c==d) return 0;
        sm*=10;
        sm += c; 
        sm %= m;
    }
    if(sm == 0) return 1;
    else return 0;
}
void solve (){
    int m,d;
    cin >> m >> d;
    string a,b;
    cin >> a >> b;
    //cout << cal(b,m,d);
    cout << ((cal(b,m,d) - cal(a,m,d))%MOD + check(a,m,d) + MOD)%MOD;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}