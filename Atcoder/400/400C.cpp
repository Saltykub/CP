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
    ll n;
    cin >> n;
    ll ans = 0;
    n/=2;
    ll l = 0, r = 1e9;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(mid*mid > n) r = mid-1;
        else l = mid;
    }
    ans += l;
    n/=2;
    l = 0, r = 1e9;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(mid*mid > n) r = mid-1;
        else l = mid;
    }
    ans += l;
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