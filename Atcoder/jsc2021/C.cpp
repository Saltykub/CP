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
    int a,b;
    cin >> a >> b;
    ll ans = 1;
    for(int i = 1; i <= b; i++){
        if(b/i > ceil(1.0*a/i) && ceil(1.0*a/i)!=0) ans = i;
    }
    cout << ans << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}