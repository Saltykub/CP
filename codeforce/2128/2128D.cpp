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
    vector<ll> v(n), pref(n,0);
    for(auto &u:v) cin >> u;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]) pref[i]++;
        pref[i]+=pref[i-1];
    }
    ll sm = 0;
    for(int i = 0; i < n; i++){
        sm += pref[i];
        ans += (i+1)*pref[i]-sm+(i+1);
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