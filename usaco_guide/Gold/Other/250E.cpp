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
ll rng() {
	static mt19937 gen(
	    chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
void solve (){
    ll n,q;
    cin >> n;
    vll a(n), b(n);
    map<ll,ll> hash;
    for(auto &u:a) {
        cin >> u;
        if(!hash.count(u)) hash[u] = rng();
    }
    for(auto &u:b) {
        cin >> u;
        if(!hash.count(u)) hash[u] = rng();
    }
    cin >> q;
    set<ll> seen;
    vll a_xor(n);
    vll b_xor(n);
    for(int i = 0; i < n; i++){
        if(!seen.count(a[i])){
            a_xor[i] = hash[a[i]];
            seen.insert(a[i]);
        }
        if(i > 0) a_xor[i] ^= a_xor[i-1];
    }
    seen.clear();
    for(int i = 0; i < n; i++){
        if(!seen.count(b[i])){
            b_xor[i] = hash[b[i]];
            seen.insert(b[i]);
        }
        if(i > 0) b_xor[i] ^= b_xor[i-1];
    }
    while(q--){
        ll l,r;
        cin >> l >> r;
        l--; r--;
        if(a_xor[l] == b_xor[r]) cout << "Yes\n";
        else cout << "No\n";
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