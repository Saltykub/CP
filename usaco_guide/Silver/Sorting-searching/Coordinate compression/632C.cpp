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
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end(),[&](string a, string b){
        if(a + b < b + a) return 1;
        return 0;
    });
    string ans = "";
    for(auto u:v) ans+=u;
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}