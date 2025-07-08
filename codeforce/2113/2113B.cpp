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
    ll w,h,a,b;
    cin >> w >> h >> a >> b;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        if(abs(y1-y2)%b == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    else if(y1 == y2){
        if(abs(x1-x2)%a == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    else {
        if((x1-x2)%a == 0 || (y1-y2)%b == 0) cout << "Yes\n";
        else cout << "No\n";
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