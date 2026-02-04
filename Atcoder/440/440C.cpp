#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,w;
    cin >> n >> w;
    vll v(n),sm(n);
    for(auto &u:v) cin >> u;
    int cur = 0, s = 0;
    for(int i = 0; i < n; i++){
        if(cur < w) {
            sm[i] += v[i];
            if(i > 0) sm[i] += sm[i-1];
            cur++;
        }
        else {
            sm[i] += sm[i-1];
            sm[i] += v[i];
            sm[i] -= v[s++];
        }
    }
    for(int i = 2*w; i < n; i++){
        sm[i] += sm[i-2*w];
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