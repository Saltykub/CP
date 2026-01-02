#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
ll seg[4*N];
void add(ll idx, ll tl, ll tr, ll pos, ll val){
    if(pos < tl || pos > tr) return;
    if(tl == tr){
        seg[idx] = val;
        return;
    }
    ll mid = (tl+tr)/2;
    add(2*idx,tl,mid,pos,val);
    add(2*idx+1,mid+1,tr,pos,val);
    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}
ll  get(ll idx, ll tl, ll tr, ll l, ll r){
    if(l > tr || r < tl) return 0;
    if(l <= tl && tr <= r) return seg[idx];
    ll mid = (tl+tr)/2;
    return max(get(2*idx,tl,mid,l,r),get(2*idx+1,mid+1,tr,l,r));
}
void solve (){
    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);
    for(auto &u:v) cin >> u;
    map<ll,ll> mp;
    set<ll> s;
    for(auto u:v) {
        s.insert(u);
        s.insert(x/u);
    }
    ll idx = 1;
    for(auto u:s){
        mp[u] = idx++;
    }
    add(1,1,N,mp[v[0]],1);
    ll ans = 1;
    for(int i = 1; i < n; i++){
        ll target = x/v[i];
        ll cur = 0;
        if(v[i] < 0) {
            cur = max(cur,get(1,1,N,mp[target],N)+1);
         }
        if(v[i] >= 0) {
            cur = max(cur,get(1,1,N,1,mp[target])+1);
        }
        ans = max(ans,cur);
        if(get(1,1,N,mp[v[i]],mp[v[i]]) < cur){
            add(1,1,N,mp[v[i]],cur);
        }
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}