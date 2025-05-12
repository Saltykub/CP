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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = -accumulate(arr.begin(),arr.end(),0LL);
    // Check every bit 
    for(int i = 0; i < 30; i++){
        ll sm = 0;
        vector<int> pref = {1,0};
        for(auto u:arr){
            sm^=(u>>i)&1;
            ans += pref[sm^1] * (1LL<<i);
            pref[sm]++;
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