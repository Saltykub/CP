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
void solve (){
    ll a,b;
    cin >> a >> b;
    ll ta = a, tb = b;
    int mx1 = 0;
    for(int i = 0; i < 30; i++){
        int cal = (1<<i);
        if(i%2){
            a-=cal;
        }
        else {
            b-=cal;
        }
        if(a < 0 || b < 0) {
            mx1 = i;
            break;
        }
    }
    for(int i = 0; i < 30; i++){
        int cal = (1<<i);
        if(i%2){
            tb-=cal;
        }
        else {
            ta-=cal;
        }
        if(ta < 0 || tb < 0) {
            mx1 = max(mx1,i);
            break;
        }
    }
    cout << mx1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}