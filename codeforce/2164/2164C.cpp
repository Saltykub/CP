#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,m;
    cin >> n >> m;
    vll a(n);
    vector<pii> b(m);
    for(auto &u:a) cin >> u;
    for(int i = 0; i < m; i++) cin >> b[i].st;
    for(int i = 0; i < m; i++) cin >> b[i].nd;
    vector<int> z;
    vector<pii> nz;
    for(auto [u,v]:b){
        if(v == 0) z.pb(u);
        else nz.pb({u,v});
    }
    sort(nz.begin(),nz.end(),[&](pii p1, pii p2){
        if(p1.st == p2.st){
            return p1.nd > p2.nd;
        }
        return p1.st < p2.st;
    });
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    vll af;
    ll ans = 0;
    for(auto u:a) pq.push(u);
    for(auto [h,c]:nz){
        while(!pq.empty() && pq.top() < h){
            af.push_back(pq.top());
            pq.pop();
        }
        if(pq.empty()) break;
        ll top =  pq.top();
        pq.pop();
        pq.push(max(top,c));
        ans++;
    }
    while(!pq.empty()) {
        af.pb(pq.top());
        pq.pop();
    }
    // sort(af.begin(),af.end(),greater<ll>());
    // sort(z.begin(),z.end(),greater<ll>());
    // int j = 0;
    // for(int i = 0; i < z.size(); i++){
    //    if(af[j] < z[i]) continue;
    //    j++;
    //    ans++;
    //    if(j == af.size()) break;
    // }
    sort(af.begin(),af.end());
    sort(z.begin(),z.end());
    int j = 0;
    for(int i = 0; i < af.size(); i++){
       if(j == z.size()) break;
       if(z[j] > af[i]) {
        continue;
       }
       j++;
       ans++;
       if(j == z.size()) break;
    }
    cout << ans << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}