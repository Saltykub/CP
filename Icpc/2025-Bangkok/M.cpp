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
    vll p(n);
    vll idx(n+1,0);
    for(auto &u:p) cin >> u;
    for(int i = 0; i < n; i++) {
        idx[p[i]] = i;
    }
    ll sm = 0;
    vll ret;
    for(int i = n; i > 1; i--){
        int shift = -((idx[i]+sm)%i);
        if(shift <= 0) shift+=i;
        ret.pb(shift);
        sm += shift;
        sm %= i;
        sm --;
        sm %= (i-1);
        cout << sm << "\n";
    }
    ret.pb(1);
    reverse(all(ret));
    for(auto u:ret) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}