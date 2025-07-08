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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    ll y = (2*v[0]-v[1])/(n+1);
    ll x = v[0]-n*y;
    if( x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++){
        v[i] -= x*(i+1);
        v[i] -= y*(n-i);
        if(v[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}