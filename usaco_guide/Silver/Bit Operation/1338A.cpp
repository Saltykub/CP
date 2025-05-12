#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<ll> add;
ll bpow(int a,int b){
    if(b == 0) return 1;
    if(b%2){
        return bpow(a,b/2)*bpow(a,b/2)*a;
    }
    return bpow(a,b/2)*bpow(a,b/2);
}
void solve (){
    int n;
    cin >> n;
    vector<ll> v(n);
    ll mx = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) {
            mx = max(mx,v[i-1]-v[i]);
            v[i] = v[i-1];
        }
    }
    auto it = lower_bound(add.begin(),add.end(),mx);
    if(mx == 0) cout << 0 << "\n";
    else cout << it-add.begin()+1 << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i = 0; i <= 30; i++) add.pb(bpow(2,i));
    for(int i = 1; i <= 30; i++) add[i] += add[i-1];
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}