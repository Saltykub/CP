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
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    map<ll,ll> mp;
    for(auto u:v){
        mp[u]++;
    }
    ll ans = 0, cnt = 0;
    vll mx;
    for(auto [idx,val]:mp){
        if(val%2 == 0){
            ans += idx*val;
            cnt += val;
        }
        else {
            ans+=idx*(val-1);
            cnt+=val-1;
            mx.pb(idx);
        }
    }
    sort(mx.begin(),mx.end(),greater<ll>());
    if(!ans){
        cout << 0 << "\n";
    }
    else {
        int sz = mx.size();
        for(int i = 0; i < sz-1; i++){
            if(ans + mx[i+1] > mx[i]){
                ans += mx[i+1] + mx[i];
                cout << ans << "\n";
                return;
            }
        }
        for(int i = 0; i < sz; i++){
            if(ans > mx[i]){
                cout << ans + mx[i] << "\n";
                return;
            }
        }
        if(cnt == 2){
            cout << 0 << "\n";
            return;
        }
        cout << ans << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}