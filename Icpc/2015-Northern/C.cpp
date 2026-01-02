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
    string a,b;
    cin >> a >> b;
    ll sza = a.size(), szb = b.size();
    ll ans = sza * szb;
    map<char,ll> mp;
    for(auto u:a) mp[u]++;
    for(auto u:b) ans -= mp[u];
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("concatenation.in","r",stdin);
    //freopen("concatenation.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}