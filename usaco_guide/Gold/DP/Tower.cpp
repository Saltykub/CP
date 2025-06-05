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
    vector<ll> lis;
    for(int i = 0; i < n; i++){
        ll k;
        cin >> k;
        auto lb = upper_bound(lis.begin(),lis.end(),k);
        if(lb == lis.end()) lis.pb(k);
        else *lb = k;
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