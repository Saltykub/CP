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
    multiset<pii> s;
    for(int i = 0; i < n; i++){
        ll l,r;
        cin >> l >> r;
        if(r-l >= k){
            s.insert({0,-1});
            s.insert({k-1,1});
        }
        else {
            l%=k;
            r%=k;
            if(l <= r){
                s.insert({min(l,r),-1});
                s.insert({max(l,r),1});
            }
            else {
                s.insert({l,-1});
                s.insert({k-1,1});
                s.insert({0,-1});
                s.insert({r,1});
            }
        }
    }
    ll sm = 0, mx = 0;
    for(auto [idx,val]:s){
        sm -= val;
        mx = max(mx,sm);
    }
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}