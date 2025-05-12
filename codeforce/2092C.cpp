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
    ll sm = 0, mxe = 0, mxo = 0, o = 0, e = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i]%2){
            mxo = max(mxo,v[i]);
            o++;
        }
        else {
            mxe = max(mxe,v[i]);
            e++;
        }
        sm+=v[i];
    }
    if(!e || !o) cout << max(mxe,mxo) << "\n";
    else {
       cout << sm - o + 1 << "\n";
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