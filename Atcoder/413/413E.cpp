#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<ll> bpow(19);
void solve (){
    int n;
    cin >> n;
    vector<ll> v(1LL<<n);
    for(auto &u:v) cin >> u;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= (1LL<<n)-(1LL<<i); j+=(1LL<<i)){
           // cout << j << "\n";
            if(v[j] > v[j+(1LL<<(i-1))]){
                for(ll k = j; k < j+(1LL<<(i-1)); k++){
                    swap(v[k],v[k+(1LL<<(i-1))]);
                }
            }
        }
    }
    for(auto u:v) cout << u << " ";
    cout << "\n";
}
int main(){  
    ios_base::sync_with_stdio(false);cin.tie(0);
    bpow[1] = 2;
    for(int i = 2; i <= 18; i++) bpow[i] = bpow[i-1]*2;
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}