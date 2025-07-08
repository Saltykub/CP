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
    int n;
    cin >> n;
    ll ans = 0;
    stack<pii> s;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        int start = i;
        while(!s.empty() && s.top().st > x){
            auto[cur,idx] = s.top();
            s.pop();
            start = idx;
            ans = max(ans,(i-idx)*cur);
        }
        s.push({x,start});
    }
    while(!s.empty()){
        auto[cur,idx] = s.top();
        s.pop();
        ans = max(ans,(n-idx)*cur);
     }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}