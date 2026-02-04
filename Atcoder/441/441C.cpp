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
    ll n,k,x;
    cin >> n >> k >> x;
    vll v(n);
    for(auto &u:v) cin >> u;
    sort(all(v),greater<ll>());
    ll sm = 0, cur = 0, ans = 0;
    for(int i = 0; i < n; i++){
        ans += v[i];
        cur++;
        if(cur > n-k){
            sm+=v[i];
            if(sm >= x){
                cout << cur << "\n";
                return;
            }
        }
       
    }
    cout << -1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}