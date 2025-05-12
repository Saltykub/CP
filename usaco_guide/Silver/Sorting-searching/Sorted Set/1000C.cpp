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
    int n;
    cin >> n;
    vector<ll> ans(n+1);
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        ll l,r;
        cin >> l >> r;
        mp[l]++;
        mp[r+1]--;
    }
    ll idx = 0;
    for(auto it = mp.begin(); next(it) != mp.end(); it++){
        idx+=it->second;
        ans[idx] += next(it)->first - it->first;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}