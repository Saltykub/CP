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
    vector<ll> arr(n), pref(n,0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i-1] + arr[i];
    ll minpref = 0, ans = INT_MIN;
    for(int i = 0; i < n; i++){
        //cout << pref[i] << " ";
        ans = max(ans,pref[i]-minpref);
        minpref = min(minpref,pref[i]);
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