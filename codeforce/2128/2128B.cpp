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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    string ans = "";
    for(int i = 0; i < n/2; i++){
        if(i%2){
            if(v[i] > v[n-1-i]){
                ans += "LR";
            }
            else {
                ans+="RL";
            }
        }
        else {
            if(v[i] > v[n-1-i]){
                ans += "RL";
            }
            else ans += "LR";
        }
    }
    if(n%2) ans += "L";
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}