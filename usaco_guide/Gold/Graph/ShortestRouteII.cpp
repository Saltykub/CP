#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
ll dis[520][520];
void solve (){
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = LLONG_MAX;
    for(int i =  1; i <= n; i++) dis[i][i] = 0;
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[b][a],c);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX) continue;
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dis[a][b] == LLONG_MAX) cout << -1 << "\n";
        else cout << dis[a][b] << "\n";
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}