#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll n,k;
    cin >> n >> k;
    vector<int> v(n);
    map<vector<pii>,ll> mp;
    for(int i = 0; i < n; i++) cin >> v[i];
    if(k == 1) {
        cout << n*(n-1)/2;
        return;
    }
    for(auto u:v){
        vector<pii> p;
        for(int i = 2; i <= sqrt(u);i++){
            int cnt = 0;
            while(u%i == 0){
                u/=i;
                cnt++;
            }
            if(cnt%k) p.pb({i,cnt%k});
        }
        if(u != 1) p.pb({u,1});
        mp[p]++;
    }
    ll ans = 0;
    for(auto u:mp) {
        if(u.st.empty()) ans+= (u.nd) * (u.nd-1);
        else {
            vector<pii> p;
            for(auto uu:u.st){
                p.pb({uu.st,k-uu.nd});
            }
            if(p==u.st) ans += (u.nd)*(u.nd-1);
            else ans+=u.nd*mp[p];
        }
    }
    cout << ans/2 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}