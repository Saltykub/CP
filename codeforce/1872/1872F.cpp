#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int a[N];
vector<int> adj[N];
bool visited[N];
bool cycle(int s,int start)
{   
    bool cyc=false;
    if(a[s]==start)cyc=true;
    else cycle(s,start);
    return cyc;
}
void solve()
{   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){visited[i]=false;adj[i].clear();}
    int c[n+10];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        adj[a[i]].pb(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            if(cycle(i,i))
            {
                cout<<1;
            }
        }
    }

}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}