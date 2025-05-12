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
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n+1),qs(n+1,0),_xor(n+1,0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        qs[i] = qs[i-1]+arr[i];
        _xor[i] = _xor[i-1]^arr[i];
    }
    auto f = [&](int l, int r){
        return qs[r]-qs[l-1]-(_xor[r]^_xor[l-1]);
    };
    while(q--){
        int l,r;
        cin >> l >> r;
        ll mx = f(l,r);
        int ls = 1, rs = n;
        int ansl = 1,ansr = n;
        while(ls<rs){
            int mid = (ls+rs)/2;
            bool can = false;
            for(int i = 1; i <= n; i++){
                if(i+mid-1 <= n){
                    if(f(i,i+mid-1) == mx){
                        ansl = i,
                        ansr = i+mid-1;
                        can = true;
                        break;
                    }
                }
            }
            if(can) rs = mid;
            else ls = mid+1;
        }
        cout << ansl << " " << ansr << "\n";
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