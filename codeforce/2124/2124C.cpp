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
    vector<ll> a(n);
    for(auto &x:a) cin >> x;
    ll g = 0,l = 1;
    reverse(a.begin(),a.end());
    for(int i = 0; i < n; i++){
        g = __gcd(g,a[i]);
        l = (l*(a[i]/g))/(__gcd(a[i]/g,l));
    }
    cout << l << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}