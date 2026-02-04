#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+5;
bool visited[N];
vector<int> adj[N],lv[N];
int p[N];
void dfs(int s,int cur,int pa){
    if(visited[s])return;
    visited[s]=true;
    lv[cur].pb(s);p[s]=pa;
    for(auto u:adj[s])dfs(u,cur+1,pa);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        visited[i]=false;
        adj[i].clear();
        p[i]=0;
        lv[i].clear();
    }
    vector<int> node;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        if(x==1)node.pb(x);
        else {
            adj[i].pb(x);
            adj[x].pb(i);
        }
    }
    for(auto u:node){
        dfs(u,1,u);
    }
    


}

int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}