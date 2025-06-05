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
    vector<int> v(n);
    int mn = INT_MAX;
    vector<int> mx(n+1,0);
    for(auto &x:v) cin >> x;
    int cur = 1;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) cur++;
        else {
            mx[v[i-1]] = max(mx[v[i-1]],cur);
            cur = 1;
        }
    }
    mx[v[n-1]] = max(mx[v[n-1]],cur);
    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(mx[i]){
            ans = min(ans,1LL*(n-mx[i])*i);
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