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
bool CASE = true;
void solve (){
    ll n,k;
    cin >> n >> k;
    if(n == k) {
        cout << 0 << "\n";
        return;
    }
    else {
        ll l = k, r = k;
        for(ll i = 1; i <= 30; i++){
            l*=2LL;
            l--;
            r*=2LL;
            r++;
           // if(l > 1e10) break;
            if(n >= l && n <= r){
                cout << i << "\n";
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