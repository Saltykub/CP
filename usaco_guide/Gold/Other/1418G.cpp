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
const int N = 2e4+10;
bool CASE = false;
ll rng() {
	static mt19937 gen(
	    chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
void solve (){
    ll n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    map<ll,ll> h1;
    for(int i = 0; i <= n; i++) h1[i] = rng();
    vll pref(n+1,0), cnt(n+1,0);
    unordered_map<ll,ll> mp;
    queue<ll> ch[n+1];
    mp[0] = 1;
    ll ret = 0;
    ll prev = 0;
    for(int i = 0; i < n; i++){
        if(sz(ch[v[i]]) >= 3){
            ll idx = ch[v[i]].front();
            ch[v[i]].pop();
            while(prev <= idx){
                mp[pref[prev]]--;
                prev++;
            }
        }
        ll before = cnt[v[i]];
        cnt[v[i]]++;
        cnt[v[i]] %= 3;
        pref[i+1] = pref[i] + (cnt[v[i]] - before) * h1[v[i]]; // run seq +1 +1 -2 
        ret += mp[pref[i+1]];
        mp[pref[i+1]]++;
        ch[v[i]].push(i);
        //if(i == 5) cout << ret << "\n";
    }
    cout << ret;

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}