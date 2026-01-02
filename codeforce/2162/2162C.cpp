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
    ll a,b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << "\n";
    }
    else {
        ll sm = 0, sm1 = 0;
        for(int i = 32; i >= 0; i--){
            ll cha = ((1LL<<i)&a), chb = ((1LL<<i)&b);
            if(cha != chb){
                if(chb){
                    if(sm1){
                        sm += (1LL<<i);
                    }
                    else sm1 = (1LL<<i);
                }
                else {
                    sm += (1LL<<i);
                }
            }
        }
        if(sm1 > a){
            cout << -1 << "\n";
            return;
        }
        cout << 2 << "\n";
        cout << sm1 << " " << sm << "\n";
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