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
    ll n,m;
    cin >> n >> m;
    unordered_map<ll,ll> mp[11];
    vll v(n);
    for(auto &u:v) cin >> u;
    for(auto u:v){
        for(int i = 1; i <= 10; i++){
            u*=10;
            u%=m;
            mp[i][u]++;
        }
    }
    ll ret = 0;
    for(auto u:v){
        int sz = to_string(u).size();
        ll cal = u%m;
        ret += mp[sz][(m-cal)%m];
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