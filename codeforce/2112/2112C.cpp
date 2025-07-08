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
    vector<ll> v(n);
    for(auto &u:v) cin >> u;
    sort(v.begin(),v.end());
    ll mx = v[n-1];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll r = v[i]+v[j];
            ll l = mx-r;
            l = max({l,v[i],v[j]});
            if(v[i] > mx-r || v[j] > mx-r) l--;
            auto itl = upper_bound(v.begin(),v.end(),l);
            if(itl == v.end()) continue;
            auto itr = lower_bound(v.begin(),v.end(),r);
            if(itr == v.begin()) continue;
            itr--;
            int idxl = itl-v.begin(), idxr = itr-v.begin();
            idxl = max(idxl,j);
            if(idxl > idxr) continue;
            ans += idxr-idxl+1;
            if(i >= idxl && i <= idxr) ans--;
            if(j >= idxl && j <= idxr) ans--;
        }
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