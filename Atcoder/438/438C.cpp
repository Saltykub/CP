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
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    vll a(n);
    for(auto &u:a) cin >> u;
    vll v;
    //cout << "PASS";
    for(int i = 0; i < n; i++){
        if(sz(v) < 3){
            v.pb(a[i]);
        }
        else {
            int sz = sz(v);
            if(a[i] == v[sz-1] && a[i] == v[sz-2] && a[i] == v[sz-3]){
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
            else {
                v.pb(a[i]);
            }
        }
    }
    cout << sz(v);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}