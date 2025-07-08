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
    int n,m,q;
    cin >> n >> m >> q;
    map<int,ll> mp;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i*i <= m; i++){
        if(!(m%i)){
            mp[i] = 0;
            mp[m/i] = 0;
        }
    }
    for(auto [p,val]:mp){
        for(int i = 1; i <= n; i++){
            mp[p] += ((a[i]-a[i-1])%p+p)%p;
        }
    }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i,x;
            cin >> i >> x;
            for(auto [p,val]:mp){
                mp[p] -= ((a[i]-a[i-1])%p+p)%p;
                mp[p] += ((x-a[i-1])%p+p)%p;
                if(i != n){
                    mp[p] -= ((a[i+1]-a[i])%p+p)%p;
                    mp[p] += ((a[i+1]-x)%p+p)%p;
                }

            }
            a[i] = x;
        }
        else {
            int k;
            cin >> k;
            if(mp[__gcd(k,m)] < m) cout << "Yes\n";
            else cout << "No\n";
        }
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