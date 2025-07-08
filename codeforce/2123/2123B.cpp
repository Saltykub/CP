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
    int n,j,k;
    cin >> n >> j >> k;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int mx = 0;
    for(auto x:v) mx = max(mx,x);
    if(k > 1) cout << "Yes\n";
    else {
        if(v[j-1] == mx) cout << "Yes\n";
        else cout << "No\n";
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