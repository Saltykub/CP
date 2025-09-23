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
    ll ans = 0;
    ll odd = 0, even = 0;
    for(int i = 1; i < n; i+=2){
        if(a[i-1] > a[i]){
            ans += abs(a[i]-a[i-1]);
            a[i-1] = a[i];
        }
        if(i != n-1){
            if(a[i+1] > a[i]){
                ans += abs(a[i]-a[i+1]);
                a[i+1] = a[i];
            }
            if(a[i-1]+a[i+1] > a[i]){
                ans += abs(a[i]-(a[i+1]+a[i-1]));
                a[i+1] -= abs(a[i]-(a[i+1]+a[i-1]));
            }
        }
    }
    cout << ans;
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}