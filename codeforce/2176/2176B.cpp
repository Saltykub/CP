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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vll v;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') v.pb(i);
    }
    ll mx = 0;
    for(int i = 0; i < n; i++){
        auto it = upper_bound(all(v),i) - v.begin() -1;
        if(s[i] == '0'){
            if(it == -1){
                mx = max(i+n-v[v.size()-1],mx);
            }
            else {
                mx = max(abs(i-v[it]),mx);
            }
        }
    }
    cout << mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}