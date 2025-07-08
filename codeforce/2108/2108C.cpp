#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> vv;
    vv.pb(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) continue;
        vv.pb(v[i]);
    }
    vector<pii> cal;
    for(int i = 0; i < vv.size(); i++){
        cal.pb({vv[i],i});
    }
    sort(cal.begin(),cal.end(),[&](pii a, pii b){
        if(a.st != b.st) return a.st > b.st;
        return a.nd < b.nd;
    });
    vector<bool> b(n);
    int ans = 0;
    for(int i = 0; i < vv.size(); i++){
        auto [val,idx] = cal[i];
        bool can = false;
        if(idx > 0) {
            if(b[idx-1]) can = true;
        }
        if(idx < n-1){
            if(b[idx+1]) can = true;
        }
        if(!can) ans++;
        b[idx] = true;
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