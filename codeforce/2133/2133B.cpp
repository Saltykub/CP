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
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end(),greater<ll>());
    ll ret = 0;
    for(int i = 0; i < n; i+=2){
        ret += v[i];
    }
    // if(n%2) ret += v[n-1];
    cout << ret << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}