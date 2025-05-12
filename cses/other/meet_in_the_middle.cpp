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
    ll n,x,mid,ans = 0;
    cin >> n >> x;
    mid = n/2;
    vector<ll> arr(mid);
    ll mid2 = n-mid;
    for(int i = 0; i < mid; i++) cin >> arr[i];
    vector<ll> arr2(mid2);
    for(int i = 0; i < mid2; i++) cin >> arr2[i];
    vector<ll> v;
    for(ll i = 0; i < (1<<mid); i++){
        ll sm = 0;
        for(int j = 0; j < mid; j++){
           // cout << j << "\n";
            if((1LL<<j)&i) sm+=arr[j];
        }
        v.pb(sm);
    }
    sort(v.begin(),v.end());
    for(ll i = 0; i < (1<<mid2); i++){
        ll sm = 0;
        for(int j = 0; j <= mid2; j++){
            if((1LL<<j)&i) sm+=arr2[j];
        }
        auto lb = lower_bound(v.begin(),v.end(),x-sm), ub = upper_bound(v.begin(),v.end(),x-sm);
        ans += ub-lb;
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
