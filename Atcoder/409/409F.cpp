#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(N);
int fp(int x){
    if(p[x] == x) return x;
    return p[x] = fp(p[x]);
}
bool merge(int u,int v){
    int pu = fp(u), pv = fp(v);
    if(pu != pv){
        p[pu] = pv;
        return true;
    }
    return false;
}
void solve (){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) p[i] = i;
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    vector<pii> point;
    point.pb({0,0});
    for(int i = 1; i <= n; i++){
        ll x,y;
        cin >> x >> y;
        point.pb({x,y});
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            auto [x1,y1] = point[i];
            auto [x2,y2] = point[j];
            ll dis = abs(x1-x2) + abs(y1-y2);
            pq.push({dis,{i,j}});
        }
    }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            ll a,b;
            cin >> a >> b;
            for(int i = 1; i <= n; i++){
                auto[x,y] = point[i];
                ll dis = abs(x-a) + abs(y-b);
                pq.push({dis,{i,n+1}});
            }
            n++;
            point.pb({a,b});
            p[n] = n;
        }
        else if(op == 2) {
            ll k = -1;
            while(!pq.empty()){
                auto[cur,uv] = pq.top();
                auto[u,v] = uv;
                pq.pop();
                if(merge(u,v)){
                    k = cur;
                    break;
                }
            }
            while(!pq.empty() && pq.top().st == k){
                auto[cur,uv] = pq.top();
                auto[u,v] = uv;
                pq.pop();
                merge(u,v);
            }
            cout << k << "\n";
        }
        else {
            int u,v;
            cin >> u >> v;
            int pu = fp(u), pv = fp(v);
            if(pu != pv) cout << "No\n";
            else cout << "Yes\n";
        }
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