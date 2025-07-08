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
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n),d(n);
    for(auto &x:p) cin >> x;
    for(auto &x:d) cin >> x;
    int q;
    cin >> q;
    while(q--){
        ll a;
        cin >> a;
        ll cnt = 0;
        bool can = true;
        auto it = lower_bound(p.begin(),p.end(),a);
        if(it != p.end()){
            ll t = p[it-p.begin()]-a;
            t%=k;
            ll idx = it-p.begin();
            bool right = true;
            while(true){
                if(cnt >= n*n) {
                    can = false;
                    break;
                }   
                if(t%k == d[idx]){
                    right = !right;
                }
                if(right){
                    idx++;
                    if(idx < 0 || idx >= n) break;
                    t += (p[idx]-p[idx-1])%k;
                    t%=k;
                }
                else {
                    idx--;
                    if(idx < 0 || idx >= n) break;
                    t += (p[idx+1]-p[idx])%k;
                    t%=k;
                }
            cnt++;
            }
        }
       
        if(can) cout << "YES\n";
        else cout << "NO\n";
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