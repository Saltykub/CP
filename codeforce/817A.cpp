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
    ll x1,y1,x2,y2;
    ll x,y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    ll dx = abs(x1-x2), dy = abs(y1-y2);
    if(dx%x == 0 && dy%y == 0){
        if(abs(dx/x-dy/y)%2 != 1){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}