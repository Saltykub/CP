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
    int n;
    cin >> n;
    vll a(n), b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    sort(all(a));
    ll mx = 0;
    ll sm = accumulate(all(b),0LL);
    ll cur =  n;
    while(sm > cur && !b.empty()){
        sm -= b.back();
        b.pop_back();
    }
    mx = max(mx,a[0]*sz(b));
    ll out = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] == out) {
            cur--;
            continue;
        }
        while(sm > cur && !b.empty()){
            sm -= b.back();
            b.pop_back();
        }
        if(sm <= cur) mx = max(mx,sz(b)*a[i]);
        out = a[i];
        cur--;
    }
    cout << mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}