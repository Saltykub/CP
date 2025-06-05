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
    vector<int> lis;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = lower_bound(lis.begin(),lis.end(),x);
        if(it == lis.end()) lis.pb(x);
        else *it = x;
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