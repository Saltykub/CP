#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    int n;
    cin >> n;
    ll mx = 0,sm = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > mx){
            sm += mx;
            mx = x;
        }
        else {
            sm += x;
        }
        if(sm == mx) ans++;
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}