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
bool CASE = false;
void solve (){
    ll n,t;
    cin >> n >> t;
    vll v(n);
    for(auto &u:v) cin >> u;
    int cur = 0;
    int op = 1;
    ll ans = 0;
    for(auto u:v){
        if(op){
            ans += u-cur;
            op = 0;
            cur = u;
        }
        else {
            if(cur+100 > u) continue;
            ans += u-cur-100;
            cur = u;
        }
    }
    if(cur+100 <= t && !op){
        ans += t-cur-100;
    }
    if(op){
        ans += t;
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