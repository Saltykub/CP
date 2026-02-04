#include<bits/stdc++.h>
#define ll int
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
vector<int> adj[N];
bool vis[N];
int cy=1;
bool can=false;
void dfs(int s,int prev){
    if(vis[s]==true)return;
    vis[s]=true;
    for(auto u:adj[s]){
        if(u==prev)continue;
        if(vis[u]==true&&u!=prev&&!can){cy=u;can=true;}
        dfs(u,s);
    }
}
void solve()
{
    int n,a,b,disa,disb;
    cin>>n>>b>>a;
    for(int i=1;i<=n;i++)vis[i]=false;
    for(int i=1;i<=n;i++)adj[i].clear();
    can=false;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);adj[y].pb(x);
    }
    // dfs find the first cycle entry node
    dfs(a,a);
    //bfs a
    for(int i=1;i<=n;i++)vis[i]=false;
    queue<pii> q;
    q.push({a,0});
    while(!q.empty()){
        int cur=q.front().st,curdis=q.front().nd;
        q.pop();
        if(vis[cur]==true)continue;
        if(cur==cy)disa=curdis;
        vis[cur]=true;
        for(auto u:adj[cur]){
            if(vis[u])continue;
            q.push({u,curdis+1});
        }
    }
    //bfs b
    for(int i=1;i<=n;i++)vis[i]=false;
    q.push({b,0});
    while(!q.empty()){
        int cur=q.front().st,curdis=q.front().nd;
        q.pop();
        //cout<<cur<<" "<<curdis<<"\n";
        if(vis[cur]==true)continue;
        if(cur==cy)disb=curdis;
        vis[cur]=true;
        for(auto u:adj[cur]){
            if(vis[u])continue;
            q.push({u,curdis+1});
        }
    }
    //cout<<disa<<" "<<disb<<" ";
    if(disa>=disb)cout<<"No";
    else cout<<"Yes";
    cout<<"\n";

}

signed main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}