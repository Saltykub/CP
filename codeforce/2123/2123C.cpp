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
    vector<int> ans(n,0);
    for(auto &x:v) cin >> x;
    vector<int> mn(n),mx(n);
    mn[0] = v[0];
    mx[n-1] = v[n-1];
    for(int i = 1; i < n; i++) mn[i] = min(mn[i-1],v[i]);
    for(int i = n-2; i >= 0; i--) mx[i] = max(mx[i+1],v[i]);
    ans[0] = 1;
    ans[n-1] = 1;
    for(int i = 1; i < n-1; i++){
       if(mn[i-1] < v[i] && v[i] < mx[i+1]) continue;
       ans[i] = 1;
    }
    for(auto u:ans) cout << u;
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