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
    vector<ll> v(n);
    multiset<ll> s;
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    s.insert(max(v[0],v[1]));
    for(int i = 2; i < n; i+=2){
        auto it = s.begin();
        if(*it < min(v[i],v[i+1])){
            s.erase(it);
            s.insert(v[i]);
            s.insert(v[i+1]);
        }
        else {
            s.insert(max(v[i],v[i+1]));
        }
    }
    for(auto u:s) ans+=u;
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