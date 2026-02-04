#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define piii pair<pii,ll>
using namespace std;
const int N = 1e6+1;
bool CASE = false;
void solve (){
    int n,q;
    cin >> n >> q;
    ll blk = sqrt(n);
    vll cnt(N,0);
    vll v(n);
    for(auto &u:v) cin >> u;
    vector<piii> qr(q);
    for(int i = 0; i < q; i++){
        cin >> qr[i].st.st >> qr[i].st.nd;
        qr[i].nd = i;
    }
    sort(all(qr),[&](piii a, piii b){
        int ca = a.st.st/blk, cb = b.st.st/blk;
        if(ca == cb){
            return a.st.nd < b.st.nd;
        }
        return ca < cb;
    });
    
    ll cur = 0;
    auto add = [&](int idx){
        ll x = cnt[v[idx]]++;
        cur += (2*x+1)*v[idx];
    };
    auto del = [&](int idx){
        ll x = --cnt[v[idx]];
        cur -= (2*x+1)*v[idx];
    };
    int mo_l = 0, mo_r = -1;
    vll ans(q);
    for(auto [lr,idx]:qr){
        auto [l,r] = lr;
        l--;
        r--;
        while(mo_l < l) {
            del(mo_l++);
        }
        while(mo_l > l){
            add(--mo_l);
        }
        while(mo_r < r){
            add(++mo_r);
        }
        while(mo_r > r){
            del(mo_r--);
        }
        ans[idx] = cur;
    }
    for(auto u:ans) cout << u << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}