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
    int n,s;
    cin >> n >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll dx,dy,x,y;
        cin >> dx >> dy >> x >> y;
        if(dx == dy && x == y) ans++;
        if(dx != dy && x+y == s) ans++;
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