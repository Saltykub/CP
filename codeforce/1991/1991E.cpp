#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> side(n+1,-1);
    queue<int> q;
    q.push(1);
    side[1] = 0;
    bool can = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto u:adj[node]){
            if(side[u] == -1){
                side[u] = side[node]^1;
                q.push(u);
            }
            else {
                can &= side[u] != side[node];
            }
        }
    }
   // cout << "pass";
    vector<int> one,two;
    if(can){
        cout << "Bob" << endl;
        for(int i = 1; i <= n; i++){
            if(side[i]) one.pb(i);
            else two.pb(i);
        }
        int o = 0, t = 0;
        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
            if(x > y) swap(x,y);
            if(x == 1 && o != one.size()){
                cout << one[o++] << " " << x << endl;
            }
            else if(x == 1 && o == one.size()){
                cout << two[t++] << " " << y << endl;
            }
            else if(x == 2 && t != two.size()){
                cout << two[t++] << " " << x << endl;
            }
            else {
                cout << one[o++] << " " << y << endl;
            }
        }
    }
    else {
        cout << "Alice" << endl;
        for(int i = 0; i < n; i++){
            cout << 1 << " " << 2 << endl;
            int x,y;
            cin >> x >> y;
        }
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {   
        solve();
    }

}