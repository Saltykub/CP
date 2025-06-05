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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i], mp[b[i]] = i;
    for(int i = 0; i < n; i++) a[i] = mp[a[i]];
    vector<int> lis;
    for(int i = 0; i < a.size(); i++){
        auto lb = lower_bound(lis.begin(),lis.end(),a[i]);
        if(lb == lis.end()) lis.pb(a[i]);
        else *lb = a[i];
    }
    cout << lis.size();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}