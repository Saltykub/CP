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
    vll a(n);
    for(auto &u:a) cin >> u;
    for(int i = 0; i < min(k,100LL); i++){
        map<ll,ll> mp;
        for(int j = 0; j < n; j++){
            mp[a[j]]++;
        }
        for(int j = 0; j < n; j++){
            a[j] = mp[a[j]];
        }
    }
    for(auto u:a){
        cout << u << " ";
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