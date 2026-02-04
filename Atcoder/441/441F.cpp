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
    ll n,m;
    cin >> n >> m;
    vector<pii> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i].st >> v[i].nd;
    }
    ll dp[n+1][m+1],mp[n+1][m+1];
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++){
        dp[i][j] = 0;
        mp[i][j] = 0;
        if(j == 0) mp[i][j] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j-1];
            mp[i][j] = mp[i][j-1];
            if(v[i].st > j) continue;
            if(dp[i][j] < dp[i-1][j-v[i].st]+v[i].nd){
                dp[i][j] = dp[i-1][j-v[i].st]+v[i].nd;
                mp[i][j] = mp[i][j-v[i].st];
            }
            else if(dp[i][j] == dp[i-1][j-v[i].st]+v[i].nd) mp[i][j] += mp[i][j-v[i].st];
        }
    }
    queue<pii> q;
    ll mx = 0;
    int z = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] > mx){
                mx = dp[i][j];
                while(!q.empty()) q.pop();
                q.push({i,j});
                z = 1;
            }
            else if(dp[i][j] == mx){
                q.push({i,j});
                z++;
            } 
        }
    }
    vector<char> ans(n+1,' ');
    vll cnt(n+1);
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        //if(j == 0) continue;
        cnt[i] += mp[i][j];
        if(mp[i][j] == mp[i][j-1] + mp[i][j-v[i].st]){
            if(j > 0) q.push({i,j-1});
            if(i > 0) q.push({i-1,j-v[i].st});
        }
        else if(mp[i][j] == mp[i][j-v[i].st]){
            if(i > 0) q.push({i-1,j-v[i].st});
        }
        else {
            if(j > 0) q.push({i,j-1});
        }
    }
    for(int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
        if(cnt[i] == z) ans[i] = 'A';
        else if(cnt[i] == 0) ans[i] =  'C';
        else ans[i] = 'B';
    }
    for(int i = 1; i <= n; i++) cout << ans[i];

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}