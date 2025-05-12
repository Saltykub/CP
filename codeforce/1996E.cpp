#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> qs[2*n+1];
    ll cur = 0;
    qs[n].push_back(0);
    // cal prefix sum
    for(int i = 1; i <= n; i++){
        cur += (s[i-1] == '0' ? -1:1);
        qs[cur+n].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < 2*n+1; i++){
        ll sm = 0;
        for(auto u:qs[i]){
            ans += (n-u+1)*sm;
            ans %= mod;
            sm += u+1;
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}