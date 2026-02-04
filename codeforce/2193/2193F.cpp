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
    int n,ax,ay,bx,by;
    cin >> n >> ax >> ay >> bx >> by;
    map<ll,ll> mn,mx;
    vll x(n), y(n);
    for(auto &u:x) cin >> u;
    for(auto &u:y) cin >> u;
    for(int i = 0; i < n; i++){
        if(!mn[x[i]]) mn[x[i]] = y[i];
        if(!mx[x[i]]) mx[x[i]] = y[i];
        mn[x[i]] = min(mn[x[i]],y[i]);
        mx[x[i]] = max(mx[x[i]],y[i]);
    }
    ll ret = bx-ax;
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    ll dpl = 0, dpr = 0, l = ay, r = ay;
    for(auto u:x){
        ll curl = mn[u], curr = mx[u];
        ll tmpl, tmpr;
        tmpl = min(dpl+abs(l-curr)+abs(curr-curl),dpr+abs(r-curr)+abs(curr-curl));
        tmpr = min(dpl+abs(l-curl)+abs(curr-curl),dpr+abs(r-curl)+abs(curr-curl));
        dpl = tmpl;
        dpr = tmpr;
        l = curl;
        r = curr;
    }
    cout << ret + min(dpl+abs(l-by),dpr+abs(r-by)) << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}