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
    ll x,y;
    cin >> x >> y;
    if(x < y) swap(x,y);
    if(x == y) cout << -1 << "\n";
    else {
        for(int i = 0; i <= 60; i++){
            if(1LL<<i >= x){
                cout << (1LL<<i)-x << "\n";
                return;
            }
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