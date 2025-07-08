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
    vector<int> tmp(v);
    sort(tmp.begin(),tmp.end());
    if(tmp == v){
        cout << "No\n";
        return;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(v[i] != tmp[i]) ans.pb(v[i]);
    }
    cout << "Yes\n";
    cout << ans.size() << "\n";
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}