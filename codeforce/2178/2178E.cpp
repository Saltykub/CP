#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll ask(int l, int r){
    cout << "? " <<  l << " " << r << endl;
    ll ret;
    cin >> ret;
    return ret;
}
void solve (){
    int n;
    cin >> n;
    ll l = 1, r = n;
    while(l < r){
        ll cl = l, cr = r, cc = l;
        ll target = ask(cl,cr)/2;
        while(cc < cr){
            ll m = (cc+cr)/2;
            ll cal = ask(cl,m);
            if(cal < target){
                cc = m+1;
            }
            else cr = m;
        }
        if(cc-l+1 > r-cc){
            l = cc+1;
        }
        else {
            r = cc;
        }
    }
    ll ans = ask(r,r);
    cout << "! " << ans << endl;

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}