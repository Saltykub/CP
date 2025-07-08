#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(1000);
ll bpow(int a, int b, int m){
    if(b == 0) return 1;
    if(b % 2) return bpow(a,b/2,m) * bpow(a,b/2,m) % m * a % m;
    return bpow(a,b/2,m) * bpow(a,b/2,m) % m;
}
int fp(int n) {
    if(p[n] == n) return n;
    return p[n] = fp(p[n]);
}
bool merge(int u,int v) {
    int pu = fp(u), pv = fp(v);
    if(pu != pv){
        p[pu] = pv;
        return true;
    }
    return false;
}
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<ll,pii>> edge;
    for(int i = 0; i < n; i++) p[i] = i;
    for(auto &x:a) cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll sm = (bpow(a[i],a[j],m) + bpow(a[j],a[i],m))%m;
            edge.pb({sm,{i,j}});
        }
    }
    sort(edge.begin(),edge.end(),greater<pair<ll,pii>>());
    ll ans = 0;
    for(auto e:edge){
        auto [w,uv] = e;
        auto [u,v] = uv;
        if(merge(u,v)){
            ans += w;
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