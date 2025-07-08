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
    map<ll,vector<ll>> mpl, mpr;
    set<ll> s;
    for(int i = 0; i < n; i++){
        if(d[i] == 0) s.insert(p[i]);
        mpr[((d[i]-p[i])%k+k)%k].pb(p[i]);
        mpl[(d[i]+p[i])%k].pb(p[i]);
    }
    auto findr = [&](ll x, ll t){
        ll val = ((t-x)%k+k)%k;
        auto &v = mpr[val];
        auto it = lower_bound(v.begin(),v.end(),x+1);
        if(it == v.end()) return -1LL;
        return *it;
    };
    auto findl = [&](ll x, ll t){
        ll val = (t+x)%k;
        auto &v = mpl[val];
        auto it = lower_bound(v.begin(),v.end(),x);
        if(it == v.begin()) return -1LL;
        it--;
        return *it;
    };
    int q;
    cin >> q;
    map<pii,bool> dp;
    while(q--){
        ll a;
        cin >> a;
        set<pii> state;
        bool can = false;
        ll dir = 1;
        if(s.count(a)) dir^=1;
        ll t = 0;
        for(int i = 0; i < 2*n; i++){
            ll b = dir ? findr(a,t) : findl(a,t);
            if(b == -1) { can = true; break;}
            else {
                t += abs(a-b);
                a = b;
                dir^=1;
            }
            if(state.count({a,dir})) break;
            state.insert({a,dir});
            if(dp.count({a,dir})){
                can = dp[{a,dir}];
                break;
            }
        }
        for(auto [a,b]:state)  dp[{a,b}] = can;
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
    //cout << mpr[0].size();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}