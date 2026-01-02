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
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &u:s) cin >> u;
    vector<int> v(n+2,0);
    for(int i = 0; i < m; i++){
        int one = 0;
        for(int j = 0; j < n; j++){
            if(s[j][i]-'0') {
                one++;
                // v[j+1]++;
            } 
        }
        if(one <= n/2){
            for(int j = 0; j < n; j++){
            if(s[j][i]-'0') {
                v[j+1]++;
            } 
        }
        }
        else {
            for(int j = 0; j < n; j++){
            if(s[j][i]-'0' == 0) {
                v[j+1]++;
            } 
        }
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx,v[i]);
    }
    for(int i = 1; i <= n; i++) if(v[i] == mx) cout << i << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}