#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int cnt = 0;
void solve (){
    ll x,y;
    cin >> x >> y;
    ll ans = LLONG_MAX, ax = x, ay = y;
    ll cal = 0;
    // case make min for y 
    int mxy = 0, mxx = 0;
    for(int i = 0; i < 30; i++){
        if((1LL<<i)&x) mxx = i;
        if((1LL<<i)&y) mxy = i;
    }
    for(int i = mxy+1; i <= 30; i++){
        if(!((1LL<<i)&x)){
            if(ans > abs(y-(1LL<<i))){
                ans = abs(y-(1LL<<i));
                ax = x;
                ay = (1LL<<i);
            }
            break;
        }
    }
    for(int i = mxx+1; i <= 30; i++){
        if(!((1LL<<i)&y)){
            if(ans > abs(x-(1LL<<i))){
                ans = abs(x-(1LL<<i));
                ax = (1LL<<i);
                ay = y;
            }
            break;
        }
    }
    bool can = true;
    for(int i = 30; i >= 0; i--){
        if(can){
            if((1LL<<i)&y){
                if(!((1LL<<i)&x)){
                    cal += (1LL<<i);
                }
                else {
                    can = false;
                }
            }
        }
        else {
            if(!((1LL<<i)&x)){
                cal += (1LL<<i);
            }
        }
    }
    if(abs(y-cal) < ans){
        ans = abs(y-cal);
        ay = cal;
        ax = x;
    }
    cal = 0;
    can = true;
    for(int i = 30; i >= 0; i--){
        if(can){
            if((1LL<<i)&x){
                if(!((1LL<<i)&y)){
                    cal += (1LL<<i);
                }
                else {
                    can = false;
                }
            }
        }
        else {
            if(!((1LL<<i)&y)){
                cal += (1LL<<i);
            }
        }
    }
    if(abs(x-cal) < ans){
        ax = cal;
        ay = y;
        ans = abs(x-cal);
    }
    //cout << (1<<30) << " " << mxy << " ";
    cout << ax << " " << ay << '\n';
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   

        solve();
    }
}