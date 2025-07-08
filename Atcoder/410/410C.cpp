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
    int n,q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++) v[i] = i;
    ll offset = 0;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll idx,val;
            cin >> idx >> val;
            idx+=offset;
            idx%=n;
            if(idx == 0) idx = n;
            v[idx] = val;
        }
        else if(op == 2){
            ll idx;
            cin >> idx;
            idx+=offset;
            idx%=n;
            if(idx == 0) idx = n;
            cout << v[idx] << "\n";
        }
        else {
            ll k;
            cin >> k;
            offset+=k;
            offset%=n;
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