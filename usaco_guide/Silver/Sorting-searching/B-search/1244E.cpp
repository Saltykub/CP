#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
bool cal(vector<ll> arr, vector<ll> p,ll d, ll k){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int ub = upper_bound(arr.begin(),arr.end(),arr[i]+d)-arr.begin();
        ll use = i*arr[i] - p[i] + p[n] - p[ub] - (n-ub)*(arr[i]+d);
        if(use <= k) return true;
    }
    for(int i = 0; i < n; i++){
        int lb = lower_bound(arr.begin(),arr.end(),arr[i]-d)-arr.begin();
        ll use = lb*(arr[i]-d) - p[lb] + p[n] - p[i] - (n-i)*arr[i];
        if(use <= k) return true;
    }
    return false;
}
void solve (){
    ll n,k;
    cin >> n >> k;
    ll l = 0, r = 0;
    vector<ll> arr(n), p(n+1,0);
    for(int i = 0; i < n; i++) cin >> arr[i], r = max(r,arr[i]);
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++) p[i+1] = p[i] + arr[i];
    sort(arr.begin(),arr.end());
    while(l < r){
       ll mid = (l+r)/2;
       if(cal(arr,p,mid,k)) r = mid;
       else l = mid+1;
       //cout << l << " " << r << "\n";
    }
    cout << l;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
