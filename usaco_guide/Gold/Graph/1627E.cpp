#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const ll INF = -1e18;
bool CASE = true;
void solve (){
    int n,m,k;
    cin >> n >> m >> k;
    int cnt = 1;
    vector<ll> x(n+1,0);
    vector<ll> dp(2*k+3,INF);
    vector<pii> to(2*k+3);
    vector<vector<pii>> row(n+1); 
    row[1].pb({1,cnt++});
    dp[1] = 0;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 0; i < k; i++){
        ll a,b,c,d,h;
        cin >> a >> b >> c >> d >> h;   
        row[a].pb({b,cnt++});
        row[c].pb({d,cnt++});
        to[cnt-2] = {cnt-1,h}; // moving from row a to row c;
    }
    row[n].pb({m,cnt});
    for(int i = 1; i <= n; i++){
        sort(row[i].begin(),row[i].end());
        for(int j = 1; j < row[i].size(); j++){
            dp[row[i][j].nd] = max(dp[row[i][j].nd], dp[row[i][j-1].nd] + 1LL * x[i] * (row[i][j-1].st - row[i][j].st));
        }
        for(int j = row[i].size()-2; j >= 0; j--){
            dp[row[i][j].nd] = max(dp[row[i][j].nd], dp[row[i][j+1].nd] + 1LL * x[i] * (row[i][j].st - row[i][j+1].st));
        }
        for(auto [r,idx]:row[i]){
            if(to[idx].st && dp[idx] != INF){
                dp[to[idx].st] = max(dp[to[idx].st], dp[idx] + to[idx].nd);
            }
        }
    }
    if(dp[cnt] == INF){
        cout << "NO ESCAPE\n";
    }
    else cout << - dp[cnt] << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}