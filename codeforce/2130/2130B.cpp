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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    ll sm = 0;
    for(auto u:v) sm+=u;
    int z = 0, o = 0, t = 0;
    for(auto u:v){
        if(u == 0) z++;
        if(u == 1) o++;
        if(u == 2) t++;
    }
    if(sm > k){
        for(auto u:v) cout << u << " ";
        cout << "\n";
    }
    else if(sm == k){
        cout << -1 << "\n";
    }
    else {
        if(k-sm > 1) {
            cout << -1 << "\n";
        }
        else {
            for(int i = 0; i < z; i++) cout << 0 << " ";
            for(int i = 0; i < t; i++) cout << 2 << " ";
            for(int i = 0; i < o; i++) cout << 1 << " ";
            cout << "\n";
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