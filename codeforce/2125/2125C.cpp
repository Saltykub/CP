#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll cal(ll n){
    return n/2 + n/3 + n/5 + n/7 - n/6 - n/10 - n/14 - n/15- n/21 - n/35 + n/30 + n/70 + n/42 + n/105 - n/210;
}
void solve (){
    ll l,r;
    cin >> l >> r;
    cout << r-l+1-(cal(r)-cal(l-1)) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}