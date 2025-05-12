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
    int sx,sy,px,py,sz;
    cin >> sx >> sy >> px >> py >> sz;
    string wind;
    cin >> wind;
    vector<pii> pref(wind.size(),{0,0});
    for(int i = 0; i < wind.size(); i++){
        if(wind[i] == 'U') pref[i].nd++;
        if(wind[i] == 'D') pref[i].nd--;
        if(wind[i] == 'R') pref[i].st++;
        if(wind[i] == 'L') pref[i].st--;
        if(i > 0) {
            pref[i].st += pref[i-1].st;
            pref[i].nd += pref[i-1].nd;
        }
    }
    
    ll l = 1, r = 1e18;
    while(l < r){
        ll mid = (l+r)/2;
        ll wx, wy, use;
        wx = (mid/wind.size())*pref[wind.size()-1].st;
        wy = (mid/wind.size())*pref[wind.size()-1].nd;
        if(mid%wind.size()){
            wx+=pref[mid%wind.size()-1].st;
            wy+=pref[mid%wind.size()-1].nd;
        }
        use = abs((sx+wx)-px) + abs((sy+wy)-py);
        if(use <= mid) r = mid;
        else l = mid+1;
       // cout << l << " " << r << "\n";
    }
    cout << ((l == 1e18)?-1:l);  
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}