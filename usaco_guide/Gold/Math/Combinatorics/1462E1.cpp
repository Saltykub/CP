#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = true;

ll choose(ll n, ll r){
    return n*(n-1)/2;
}
void solve (){
   ll n,m,k;
   cin >> n;
   k = 2, m = 3;
   ll ans = 0;
   vector<ll> v(n);
   for(int i = 0; i < n; i++) cin >> v[i];
   sort(v.begin(),v.end());
   for(int i = 0; i < n; i++){
        auto ub = upper_bound(v.begin(),v.end(),v[i]+k);
        if(ub == v.begin()) continue;
        int idx = ub - v.begin()-1;
        int length = idx - i + 1;
        if(length - 1 < m - 1) continue;
        ans += choose(length-1,m-1);
   }
   cout <<ans << "\n";
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}