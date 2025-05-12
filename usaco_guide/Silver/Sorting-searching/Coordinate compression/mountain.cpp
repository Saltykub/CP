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
    freopen("mountains.in","r",stdin);
    ll n;
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++){
       int x,y;
       cin >> x >> y;
       v[i].st = x-y;
       v[i].nd = x+y;
    }
    sort(v.begin(),v.end(), [&](pii a,pii b){
        if(a.st == b.st) return a.nd > b.nd;
        return a.st < b.st;
    });
    ll mx = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i].nd > mx) {
            cnt ++;
            mx = v[i].nd;
        }
    }
    freopen("mountains.out","w",stdout);
    cout << cnt;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}