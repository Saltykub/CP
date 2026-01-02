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
const int MOD = 1006903069;
bool CASE = false;
void solve (){
    ll n = 0;
    ll ka,kb;
    cin >> n >> ka;
    map<pii,ll> mpa,mpb;
    while(ka--){
        ll i,j,x;
        cin >> i >> j >> x;
        mpa[{i,j}] = x;
    }
    cin >> kb;
    ll sm = 0;
    while(kb--){
        ll i,j,x;
        cin >> i >> j >> x;
        sm += mpa[{j,i}] * x;
        sm %= MOD;
    }
    cout << sm;
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}