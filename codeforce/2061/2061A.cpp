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
    ll ans = 0, one = 0;
    bool have = false;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x%2) ans++;
        else have = true;
    }
    if(have) ans++;
    else ans--;
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