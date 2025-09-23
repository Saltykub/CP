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
    vector<pair<char,int>> v;
    ll sm = 0;
    while(n--){
        char c;
        int x;
        cin >> c >> x;
        sm += x;
        v.pb({c,x});
    }
    if(sm > 100){
        cout << "Too Long";
    }
    else {
        string ans = "";
        for(auto [c,x]:v){
            for(int i = 0; i < x; i++){
                ans += c;
            }
        }
        cout << ans;
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