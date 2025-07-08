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
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int bb = b^1;
    if(a > b){
        if((a^1) > b) {
            cout << -1 << "\n";
            return;
        }
        a^=1;
        ll cnt = y;
         for(int i = a; i < b; i++){
            if((i^1) == i+1){
                cnt += min(x,y);
            }
            else cnt += x;
         }
         cout << cnt << "\n";
        return;
    }
    ll cnt = 0;
    for(int i = a; i < b; i++){
            if((i^1) == i+1){
                cnt += min(x,y);
            }
            else cnt += x;
     }
     cout << cnt << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}