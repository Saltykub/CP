#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll n,k;
    cin >> n >> k;
    multiset<ll> s;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].st >> v[i].nd;
    sort(v.begin(),v.end(),[&](pii a, pii b){
        if(a.nd == b.nd) return a.st > b.st;
        return a.nd < b.nd;
    });
    ll cnt = 0;
    for(int i = 0; i < k; i++) s.insert(0);
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(v[i].first);
        if(it == s.begin()) continue;
        //cout << v[i].first << "\n";
        s.erase(--it);
        cnt++;
        s.insert(v[i].second);
    }
   cout << cnt;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}