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
    vector<int> ans;
    set<int> s;
    for(auto u:v){
        if(s.find(u) == s.end()){
            ans.pb(u);
            s.insert(u);
        }
    }
    for(int i = 1; i <= n; i++){
        if(s.find(i) == s.end()){
            ans.pb(i);
        }
    }
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