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
    int cnt = 0;
    set<int> prev;
    set<int> cur;
    int ans = 0;
    cur.insert(v[0]);
    for(int i = 1; i < n; i++){
        if(prev.empty()) {
            ans++;
            prev = cur;
            cur.clear();
        }
        cur.insert(v[i]);
        if(prev.find(v[i]) != prev.end()){
            prev.erase(prev.find(v[i]));
        }
    }
    if(prev.empty()) ans++;
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}