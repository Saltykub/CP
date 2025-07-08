#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,l,r,k;
    cin >> n >> l >> r >> k;
    if(n%2) cout << l << "\n";
    else {
        if(n==2){
            cout << -1 << "\n";
        }
        else {
            ll nxt = 0;
            for(ll i = 60; i >= 0; i--){
                if((1LL << i)&l){
                   // cout << i << "\n";
                    nxt = (1LL<<(i+1));
                    break;
                }
            }
            if(r < nxt) {
                cout << -1 << "\n";
            }
            else {
                if(k == n || k == n-1){
                    cout << nxt << "\n";
                }
                else {
                    cout << l << "\n";
                }
            }
        }
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