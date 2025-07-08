#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<ll,pair<ll,ll>>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const ll INF = LLONG_MAX;
bool CASE = false;
ll dis[N][2];
void solve (){
    int n,m;
    cin >> n >> m;
    vector<pii> adj[n+1];
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    for(int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = INF;
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,{1,1}});
    dis[1][1] = 0;
    while(!pq.empty()){
        auto [cur,top] = pq.top();
        auto [tic,node] = top;
        pq.pop();
        if(dis[node][tic] < cur) continue;
        for(auto [v,w]:adj[node]){
            if(tic){
                if(dis[v][0] > w/2+cur){
                    dis[v][0] = w/2+cur;
                    pq.push({dis[v][0],{0,v}});
                }
                if(dis[v][1] > w+cur){
                    dis[v][1] = w+cur;
                    pq.push({dis[v][1],{1,v}});
                }
            }
            else {
                if(dis[v][0] > w+cur){
                    dis[v][0] = w+cur;
                    pq.push({dis[v][0],{0,v}});
                }
            }
        }
    }
    cout << dis[n][0];


}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}