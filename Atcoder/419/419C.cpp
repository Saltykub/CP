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
    ll mxx = 0, mxy = 0, mnx = INT_MAX, mny = INT_MAX;
    while(n--){
        ll x,y;
        cin >> x >> y;
        mxx = max(mxx,x);
        mnx = min(mnx,x);
        mxy = max(mxy,y);
        mny = min(mny,y);
    }
    cout << max((mxx-mnx+1)/2,(mxy-mny+1)/2);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}