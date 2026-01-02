#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,k,x;
    cin >> n >> k >> x;
    vll v(n);
    for(auto &u:v) cin >> u;
    sort(v.begin(),v.end());
    ll l = 0, r = x;
    vector<ll> ans;
    while(l < r){
        ll mid = (l+r+1)/2;
        vector<ll> vv;
        ll cur = 0,i = 0;
        while(vv.size() != k && i < n){
            if(v[i]-cur < mid){
                cur = v[i]+mid;
                i++;
            }
            else {
                vv.pb(cur);
                cur++;
            }
        }
        while(vv.size() != k && cur <= x){
           vv.pb(cur);
           cur++;
        }
        if(vv.size() == k){
            ans = vv;
            l = mid;
        }
        else {
            r = mid-1;
        }
        // cout << l << " " << r << "\n";
    }
    if(l == 0){
        int cnt = 0;
        for(int i = 0; i < k; i++) cout << i << " ";
        cout << "\n";
        return;
    }
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}