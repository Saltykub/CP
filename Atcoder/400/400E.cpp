#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+1;
bool CASE = true;
vector<int> isprime(N,0);
vector<ll> prime;
vector<ll> ans;
void init(){
    for(int i = 2; i < N; i++){
        if(!isprime[i]){
            for(ll j = i+i; j < N; j+=i){
                isprime[j]++;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(isprime[i] == 2) ans.pb(i*i); 
    }
    sort(ans.begin(),ans.end());
}
void solve (){
    ll n;
    cin >> n;
    auto ub = prev(upper_bound(ans.begin(),ans.end(),n));
    cout << *ub << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    init();
    //cout << (ll) 1e12/4;
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();    
    }
}