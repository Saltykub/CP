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
    vector<ll> arr(n);
    for(auto &u:arr) cin>> u;
    ll ans = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(auto u:arr){
        for(int i = 0; i < 60; i++){
            if(!((1LL<<i)&u)){
                pq.push({(1LL<<i),u+(1LL<<i)});
                break;
            }
        }
        ans += __builtin_popcount(u);
    }
    while(!pq.empty()){
        auto[sm,u] = pq.top();
        pq.pop();
        k-=sm;
        if(k < 0) break;
        ans++;
        for(int i = 0; i < 60; i++){
            if(!((1LL<<i)&u)){
                pq.push({(1LL<<i),u+(1LL<<i)});
                break;
            }
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