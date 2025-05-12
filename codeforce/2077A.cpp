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
    vector<int> v(2*n);
    for(int i = 0; i < 2*n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    ll sm = 0;
    vector<int> ans;
    for(int i = 0; i < 2*n-2; i+=2){
        ans.pb(v[i+1]);
        ans.pb(v[i]);
        sm+=v[i+1]-v[i];
    }
    if(sm >= v[2*n-1]){
        cout << sm+v[2*n-1] - v[2*n-2] << " ";
        for(auto u:ans) cout << u << " ";
        cout << v[2*n-1] << " " << v[2*n-2] << "\n";
    }
    else {
        cout << v[2*n-1] << " ";
        for(auto u:ans) cout << u << " ";
        cout << v[2*n-1]-sm + v[2*n-2] << " " << v[2*n-2] << "\n";
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