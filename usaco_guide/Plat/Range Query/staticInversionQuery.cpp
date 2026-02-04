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
const int N = 1e5+1;
bool CASE = false;
int fw[N];
void upd(int i,int val){
    for(; i < N; i+=(i&-i)) fw[i]+=val;
}
ll get(int i){
    ll ret = 0;
    for(;i;i-=(i&-i)) ret += fw[i];
    return ret;
}
void solve (){
    int n,q;
    cin >> n >> q;
    ll blk = sqrt(n);
    vll v(n),com;
    set<int> s;
    for(auto &u:v) cin >> u, s.insert(u);
    unordered_map<int,int> mp;
    int p = 1;
    for(auto u:s){
        mp[u] = p++; 
    }
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
    auto addl = [&](int idx){
       ll cidx = mp[v[idx]];
       cur += get(cidx-1);
       upd(cidx,1);
    };
    auto dell = [&](int idx){
       ll cidx = mp[v[idx]];
       cur -= get(cidx-1);
       upd(cidx,-1);
    };
    auto addr = [&](int idx){
       ll cidx = mp[v[idx]];
       cur += get(N-1)-get(cidx);
       upd(cidx,1);
    };
    auto delr = [&](int idx){
       ll cidx = mp[v[idx]];
       cur -= get(N-1)-get(cidx);
       upd(cidx,-1);
    };
    int mo_l = 0, mo_r = -1;
    vll ans(q);
    for(auto [lr,idx]:qr){
        auto [l,r] = lr;
        r--;
        while(mo_r < r){
            addr(++mo_r);
        }
        while(mo_r > r){
            delr(mo_r--);
        }
        while(mo_l < l) {
            dell(mo_l++);
        }
        while(mo_l > l){
            addl(--mo_l);
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