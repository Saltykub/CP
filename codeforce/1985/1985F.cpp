#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    ll h,n;
    cin >> h >> n;
    int atk[n], c[n];
    for(int i = 0; i < n; i++) cin >> atk[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    ll l = 1, r = 4e10;
    while( l < r){
        ll m = (l+r)/2;
        ll dmg = 0;
        for(int i = 0; i < n; i++){
            dmg += (((m-1)/c[i])+1)*atk[i];
            if(dmg >= h) break;
        }
        if(dmg >= h) r = m;
        else l = m+1;
    }
    cout << l << "\n";

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