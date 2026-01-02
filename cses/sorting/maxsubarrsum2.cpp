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
void solve (){
    ll n,l,r;
    cin >> n >> l >> r;
    vll v(n), pref(n);
    for(auto &u:v) cin >> u; 
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pref[0] = v[0];
    for(int i = 1; i < n; i++){
      pref[i] += pref[i-1] + v[i];
    }
    ll mx = LLONG_MIN;
    pq.push({0,-1});
    int j = 0;
    for(int i = l-1; i < r; i++){
        mx = max(mx,pref[i]-pq.top().st);
        pq.push({pref[j],j});
        j++;
    }
    int k = 0;
    for(int i = r; i < n; i++){
       while(pq.top().nd < k){
         pq.pop();
       }
      mx = max(mx,pref[i]-pq.top().st);
      pq.push({pref[j],j});
      j++;
      k++;
    }
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}