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
    int m,n;
    cin >> n >> m;
    string s; 
    cin >> s;
    string ss = "0"+s;
    s = ss;
    vector<vector<int>> dp(n+1,vector<int>(26,0));
    vector<int> adj[n+1];
    vector<int> in(n+1,0);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        in[v]++;
        adj[u].pb(v);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) {
            q.push(i);
            dp[i][s[i]-'a'] = 1;
        }
    }
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(auto u:adj[fr]){
            in[u]--;
            for(int i = 0; i < 26; i++){
                if(s[u]-'a' != i) dp[u][i] = max(dp[u][i],dp[fr][i]);
                else dp[u][i] = max(dp[u][i],dp[fr][i]+1);
            }
            if(in[u] == 0) q.push(u);
        }
    }
    for(int i =  1; i <= n; i++){
        if(in[i] != 0) {
            cout << "-1";
            return;
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            mx = max(mx,dp[i][j]);
        }
    }
    cout << mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}