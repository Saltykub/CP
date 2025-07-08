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
    ll l,r;
    cin >> l >> r;
    ll ans = 0;
    vector<ll> pw(11,10);
    int have = (r-l);
    for(int i = 2; i <= 10; i++) pw[i]*=pw[i-1];
    pw[0] = 1;
    int tmp = l;
    for(int i = 1; i <= 9; i++){
        ll li = l%10, ri = r%10, tmpi = tmp%10;
        //cout << tmp << " ";
        if(tmpi == li){
            if(have){
                tmp++;
                tmpi++;
                tmpi%=10;
                have--;
            }
            else {
                ans++;
            }
        }
        if(tmpi == ri){
            if(have){
                tmp++;
                tmpi++;
                have--;
            }
            else {
                ans++;
            }
        }
        l/=10;
        r/=10;
        tmp/=10;
        have/=10;
        if(l == 0 || r == 0) break;
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