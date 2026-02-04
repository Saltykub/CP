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
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    map<ll,ll> mp,mp2;
    ll ret = 0;
    for(int i = 0; i < n; i++){
        if(v[i]%5 == 0){
            ll target = v[i]/5;
            ll sv = target*7, th = target*3;
            ret += mp[sv]*mp[th];
        }
        mp[v[i]]++;
    }
    for(int i = n-1; i >= 0; i--){
        if(v[i]%5 == 0){
            ll target = v[i]/5;
            ll sv = target*7, th = target*3;
            ret += mp2[sv]*mp2[th];
        }
        mp2[v[i]]++;
    }
    cout << ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}