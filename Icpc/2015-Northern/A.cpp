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
    int h,w;
    cin >> h >> w;
    double ans = 0;
    ans = max(ans,min(1.0*h,1.0*w/3));
    ans = max(ans,min(1.0*w,1.0*h/3));
    ans = max(ans,min(1.0*h/2,1.0*w/2));
    cout << ans;
}
int main(){   
    //ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("alex.in","r",stdin);
    freopen("alex.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}