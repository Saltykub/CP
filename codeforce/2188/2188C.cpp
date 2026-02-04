#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    vll tmp = v;
    sort(all(tmp));
    vll move;
    for(int i = 0; i < n; i++){
        if(tmp[i] != v[i]){
            move.pb(v[i]);
        }
    }
    if(move.empty()){
        cout << -1 << "\n";
        return;
    }
    sort(all(move));
    int mn = tmp[0], mx = tmp[n-1];
    ll l = 1, r = mx+1;
    while(l < r){
        ll mid = (l+r+1)/2;
        bool can = true;
        for(auto u:move){
            if(u >= mn+mid || u <= mx-mid){
                continue;
            }
            can = false;
        }
        if(!can){
            r = mid-1;
        }
        else l = mid;
    }
    cout << l << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}