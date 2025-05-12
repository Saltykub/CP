#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
vector<int> adj[N];
int dp[N][20];
void dfs(int node,int p){
    dp[node][0]=p;
    for(auto u:adj[node]){
        if(u!=p){
            dfs(u,node);
        }
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x; cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dfs(1,1);
    dp[1][0]=0;
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    while(q--){
        int x,k;
        cin >> x >> k;
        while(k){
            int go=floor(log2(k));
            x=dp[x][go];
            k-=pow(2,go);
        }
        if(x==0)cout<<-1;
        else cout<<x;
        cout<<" ";
    }

   
}