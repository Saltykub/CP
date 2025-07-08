#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<ll> isprime(N);
vector<ll> prime;
void init(){
    for(int i = 0; i < N; i++) isprime[i] = 1;
    isprime[1] = 0;
    for(int i = 2; i < N; i++){
       // cout << "PASS";
        if(isprime[i]){
            prime.pb(i);
            for(int j = 2*i; j < N; j+=i){
                isprime[j] = 0;
            }
        }
    }
}
void solve (){
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> cnt(n+1,0);
    for(auto &x:v) cin >> x, cnt[x]++;
    ll ans = 0;
    ll pr = 0;
    for(auto u:prime){
        if(u > n) break;
        pr += cnt[u];
    }   
    for(auto u:prime){
        if(u > n) break;
        ans += cnt[u] * (pr-cnt[u]);
    }
    ans/=2;
    for(int i = 0; i < prime.size(); i++){
        if(prime[i] > n) break;
        for(int j = i; j < prime.size(); j++){
            ll mul = prime[i]*prime[j];
            if(prime[i]*prime[j] > n) break;
            ans += cnt[prime[i]] * cnt[mul];
            if(i != j) ans += cnt[prime[j]] * cnt[mul];
            ans += cnt[mul]*(cnt[mul]+1)/2;
        }
    }
    cout << ans << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    init();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}