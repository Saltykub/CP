#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e7+10;
bool CASE = false;
vector<ll> isprime(N,1);
vector<ll> prime;
void init(){
    for(int i = 2; i < N; i++){
        if(isprime[i]){
            prime.pb(i);
            for(int j = i+i; j < N; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
void solve (){
    ll l,r;
    cin >> l >> r;
    ll ans = 1;
    ll sz = prime.size();
    for(ll i = 0; i < sz; i++){
        double lb = floor(log(l)/log(prime[i]));
        double ub = floor(log(r)/log(prime[i]));
        ans += ub-lb;
    }
    int j = 0;
    vector<bool> mp(r-l+3,true);
    //cout << r-l+3;
    for(ll i = 0; i < sz; i++){
        ll s = ceil(1.0*l/prime[i]);
        if(s*prime[i] <= r){
            for(ll j = s*prime[i]; j <= r; j+=prime[i]){
                mp[j-l] = false;
            }
        }
    }
    for(ll i = l+1; i <= r; i++){
        if(mp[i-l]) {
            ans++;
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    init();
    //cout << prime[prime.size()-1] << "\n";
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}