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
    ll n;
    cin >> n;
    map<int,int> mp;
    for(ll i = 1; i <= sqrt(n); i++){
        for(ll j =  i+1; j <= sqrt(n); j++){
            if(i*i + j*j <= n) mp[i*i+j*j]++;
        }
    }
    vll ans;
    for(auto [a,b]:mp){
        if(b == 1) ans.pb(a);
    }
    cout << sz(ans) << "\n";
    for(auto u:ans) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}