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
    ll n,b;
    cin >> n >> b;
    vll v(n-1);
    bool good = false;
    for(auto &u:v){
        cin >> u;
        if(u >= 0) {
            b+=u;
            good = true;
        }
    }
    sort(all(v));
    if(good) cout << b;
    else {
        if(abs(v[sz(v)-1]) <= b){
            cout << b + v[sz(v)-1];
        }
        else cout << -1;
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