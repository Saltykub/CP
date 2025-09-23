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
    vector<ll> p(n), s(n);
    for(auto &x:p) cin >> x;
    for(auto &x:s) cin >> x;
    for(int i = 0; i < n-1; i++){
        if(__gcd(p[i],s[i+1]) != p[n-1]){
            cout << "No\n";
            return;
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(p[i]%p[i+1] != 0) {
            cout << "No\n";
            return;
        }
    }
    for(int i = 1; i < n; i++){
        if(s[i]%s[i-1] != 0){
            cout << "No\n";
            return;
        }
    }
    if(p[n-1] != s[0]){
        cout << "No\n";
        return; 
    }
    cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}