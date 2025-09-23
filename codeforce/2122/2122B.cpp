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
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a > c){
            ans += a-c;
            ans += abs(b-d);
            if(b > d){
                ans +=  2*c;
            }
        }
        else {
            ans += c-a;
            ans += abs(b-d);
            if(b > d){
                ans += 2*a;
            }
        }
    }
    cout << ans/2 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}