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
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end());
    vector<ll> seg;
    for(int i = 1; i < n; i++){
        seg.pb(v[i]-v[i-1]);
    }
    ll ans = v[n-1]-v[0];
    sort(seg.begin(),seg.end(),greater<ll>());
    for(int i = 0; i < m-1; i++){
        ans-=seg[i];
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