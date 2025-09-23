#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end());
    vector<ll> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] += pref[i] + v[i];
    while(q--){
        int b;
        cin >> b;
        auto it = lower_bound(v.begin(),v.end(),b-1);
        if(b > v.back()) cout << -1 << "\n";
        else if(b == 1) cout << 1 << "\n";
        else cout << pref[it-v.begin()] + (b-1)*(n-(it-v.begin()))+1 << "\n";
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