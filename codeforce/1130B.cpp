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
    vector<int> v(2*n);
    for(auto &x:v) cin >> x;
    vector<int> p[n+1];
    for(int i = 0; i < 2*n; i++) p[v[i]].pb(i);
    ll o = 0, z = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        ans += min(abs(o-p[i][0])+abs(z-p[i][1]),abs(z-p[i][0])+abs(o-p[i][1]));
        z = p[i][1];
        o = p[i][0];
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