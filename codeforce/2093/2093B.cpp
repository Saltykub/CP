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
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    ll ans = 0;
    bool check = false;
    for(int i = 0; i < s.size(); i++){
        if(!check){
            if(s[i] == '0') ans++;
            else check = true;
        }
        else {
            if(s[i] != '0') ans++;
        }
    }
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