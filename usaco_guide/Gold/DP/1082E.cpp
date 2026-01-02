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
    ll n,k;
    cin >> n >> k;
    vll v(n);
    map<ll,ll> mp;
    for(auto &u:v) cin >> u;
    for(auto u:v){
        mp[u]++;
    }
    ll mx = 0;
    for(auto [a,b]:mp) mx = max(mx,b);
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}