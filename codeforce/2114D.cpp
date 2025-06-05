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
    int n;
    cin >> n;
    vector<pii> tab(n);
    multiset<ll> xx, yy;
    for(int i = 0; i < n; i++){
        cin >> tab[i].st >> tab[i].nd;
        xx.insert(tab[i].st);
        yy.insert(tab[i].nd);
    }
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        int x = tab[i].st, y = tab[i].nd;
        //cout << x << " " << y << "\n";
        xx.erase(xx.find(x));
        yy.erase(yy.find(y));
        ll mxx = *xx.rbegin(), mxy = *yy.rbegin(), mnx = *xx.begin(), mny = *yy.begin();
        ll w = mxx - mnx + 1, h = mxy - mny + 1;
        //cout << w << " " << h << "\n";
        if( w > h) swap(w,h);
        if(w*h >= n) ans = min(ans,w*h);
        else ans = min(ans,w*h + w);
        xx.insert(x);
        yy.insert(y);
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}