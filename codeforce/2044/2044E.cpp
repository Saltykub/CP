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
    ll l1,r1,l2,r2,k;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll cur = 1;
    ll ans = 0;
    for(int i = 0; i <= 33; i++){
        if(i != 0) cur *= k;
        if(cur > 1000000000) break;
        if(l1*cur > r2 || r1*cur < l2 ) continue;
        ll mn = min(r1*cur,r2), mx = max(l1*cur,l2);
        ans += mn/cur - ceil(1.0*mx/cur)+1;
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