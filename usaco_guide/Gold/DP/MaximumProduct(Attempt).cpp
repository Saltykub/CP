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
    ll a, b;
    cin >> a >> b;
    string s = to_string(b);
    int mx = 0;
    string ans = "";
    for(int i = 0; i < s.size()-1; i++){
        string temp = s;
        if(temp[i] == '0') continue;
        temp[i] -= 1;
        for(int j = i+1; j < s.size(); j++) temp[j] = '9';
        if(stoll(temp) < a) continue;
        string cp = temp;
        ll cal = 1;
        for(int j = 0; j < s.size(); j++) {
            if(temp[j] != '0') break;
            temp[j] = '1';
        }
        for(auto u:temp){
            cal*=u-'0';
        }
        if(cal > mx) {
            mx = cal;
            ans = cp;
        }
    }
    ll cal = 1;
    for(auto u:s){
        cal*=u-'0';
    }
    if(cal > mx){
        ans = s;
    }
    cout << stoll(ans);
    cout << char('0'-1);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}