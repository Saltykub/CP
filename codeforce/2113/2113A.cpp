#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int cnt = 0;
void solve (){
    ll k,a,b,x,y;
    cin >> k >> a >> b >> x >> y;
    ll ans = 0;
    if(x > y){
        swap(x,y);
        swap(a,b);
    }
    else if(x == y){
        if(a > b) swap(a,b);
    }
    // x < y && a < b
    if(k >= a){
        ans += (k-a)/x + 1;
        k-= ans*x;
    }
    if(k >= b){
        ans += (k-b)/y+1;
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