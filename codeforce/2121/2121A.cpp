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
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end());
    if(s >= v[n-1]) {
        cout << s-v[0] << "\n";
    }
    else if(s <= v[0]){
        cout << v[n-1] - s << "\n";
    }
    else {
        int mn = abs(s-v[0]), mx = abs(v[n-1]-s);
        cout << mn + mx + min(mn,mx) << "\n";
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