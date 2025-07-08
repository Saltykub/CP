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
    int n;
    cin >> n;
    vector<ll> v(n,0);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<int,int> mp;
    ll sm = 0;
    for(auto u:v){
        for(int i = 0; i <= 30; i++){
           if((1LL<<i) & u) mp[i]++;
        }
        sm += u;
    }
    ll mx = 0;
    for(auto u:v){
        ll tmp = sm;
        for(int i = 0; i <= 30; i++){
            if((1LL<<i) & u){
                ll z = n-mp[i];
                tmp -= (1LL<<i)*mp[i];
                tmp += (1LL<<i)*z;
            }
        }
        mx = max(tmp,mx);
    }
    cout << mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}