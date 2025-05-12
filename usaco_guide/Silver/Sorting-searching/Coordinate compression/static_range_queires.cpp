#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 7e5+10;
bool CASE = false;
vector<pair<pii,int>> up;
vector<pii> qq;
vector<ll> acc(N,0), width(N,0), pref(N,0);
void solve (){
    ll n,q;
    cin >> n >> q;
    set<ll> idx;
   
    while(n--){
        ll l,r,v;
        cin >> l >> r >> v;
        idx.insert(l);
        idx.insert(r-1);
        idx.insert(r);
        up.pb({{l,r},v});
    }
    while(q--){
        ll l,r;
        cin >> l >> r;
        idx.insert(l-1);
        idx.insert(r);
        idx.insert(r-1);
        qq.pb({l,r});
    }
    // get compress idx;
    map<ll,ll> mp;
    int i = 0;
    vector<ll> val;
    for(auto u:idx){
        mp[u] = i;
        i++;
        val.pb(u);
    }
    sort(val.begin(),val.end());
    width[0] = val[0];
    for(int i = 1; i < val.size(); i++){
        width[i] = val[i]-val[i-1];
        //cout << width[i] << " ";
    }
    for(int i = 0; i < up.size(); i++){
        auto [lr,v] = up[i];
        auto [l,r] = lr;
        acc[mp[l]] += v;
        acc[mp[r]] -= v;
    }
    for(int i = 1; i < acc.size(); i++) acc[i]+=acc[i-1];
    pref[0] = acc[0]*width[0];
    for(int i = 1; i < val.size(); i++){
        pref[i] = pref[i-1] + acc[i-1]*(width[i]-1) + acc[i];
    }
    for(int i = 0; i < qq.size(); i++){
        auto[l,r] = qq[i];
        cout << pref[mp[r-1]]-pref[mp[l-1]] << "\n";
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