#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pii pair<ll,ll>
#define pb push_back
using namespace std;
const int N = 3e5+10;
const int mod = 998244353;
vector<ll> adj[N];
ll dp[N]; 
void dfs(int s,int p){
   ll cal = 1;
   for(auto u:adj[s]){
      if(u!=p){
        dfs(u,s);
        cal*=(dp[u]+1)%mod;
        cal%=mod;
      }
   }
   dp[s] += cal;
   dp[s] %= mod;
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i <  n - 1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i <= n;i++) dp[i]=0;
    dfs(1,1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[i];
        ans %= mod;
    }
   // for(int i = 1; i <= n;i++) cout << dp[i][1] << " ";
    for(int i = 1; i <= n ;i++)adj[i].clear();
    ans ++;
    ans %= mod;
    cout << ans <<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}