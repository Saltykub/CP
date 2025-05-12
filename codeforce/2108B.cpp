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
    ll n, x;
    cin >> n >> x;
    if(n == 1 && x == 0) {
        cout << -1 << "\n";
        return;
    }
    int cnt[32];
    for(int i = 0; i < 32; i++) cnt[i] = 0;
    int cntt = 0;
    for(int i = 0; i <= 31; i++){
        if((1LL<<i)&x) {
            cnt[i] = 1;
            cntt++;
        }
    }
    if(cntt >= n){
        cout << x << "\n";
    }
    else {
        ll want = n-cntt;
        // even case
        if(x == 0){
            if(n%2) cout << n-1+4 << "\n";
            else cout << n <<  "\n";
            return;
        }
        if(x == 1){
            if(n%2) cout << n << "\n";
            else cout << n-1+4 << "\n";
        }
        else if(want%2 == 0){
           cout << x + want << "\n";
        }
        else {
            cout << x + want + 1 << "\n";
        }
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}