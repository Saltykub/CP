#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
const int MOD=998244353;
vector<pii> adj[N];
ll one=0,ans=0;
void dfs(int node){
    for(auto u:adj[node]){
        if(u.second)one++;
        else ans+=one;
        ans%=MOD;
        dfs(u.first);
    }
}
void solve()
{  
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        while(num--){
            int to,w;
            cin>>to>>w;
            adj[i].pb({to,w});
        }
    }
    dfs(1);
    cout<<ans;

int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
