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
    for(auto &u:v) cin >> u;
    int idx = v[k-1];
    sort(v.begin(),v.end());
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(idx > v[i]) continue;
        cur += v[i]-idx;
        if(cur > idx) {
            cout << "No\n";
            return;
        }
        idx = v[i];
    }
    cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}