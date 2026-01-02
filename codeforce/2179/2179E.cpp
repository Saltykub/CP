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
    ll n,x,y;
    cin >> n >> x >> y;
    ll tx = x, ty = y, sm = 0;
    string s;
    cin >> s;
    vll p(n);
    for(auto &u:p) cin >> u;
    for(int i = 0; i < n; i++){
        int target = (p[i]+1)/2;
        if(s[i] == '0') x-=target;
        else y-=target;
        sm += p[i];
    }
    if(x < 0 || y < 0) {
        cout << "No\n";
        return;
    }
    if(ty == y && tx-ty < n){
        cout << "No\n";
        return;
    }
    if(tx == x && ty-tx < n){
        cout << "No\n";
        return;
    }
    else {
        if(tx + ty >= sm){
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
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