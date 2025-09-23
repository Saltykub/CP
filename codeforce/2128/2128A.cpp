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
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end(),greater<ll>());
    ll mul = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i]*mul > k){
            ans++;
        }
        else {
            mul*=2;
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}