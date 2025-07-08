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
    bool log = false;
    int q;
    cin >> q;
    int cnt = 0;
    while(q--){
        string s;
        cin >> s;
        if(s == "login") log = true;
        else if( s == "logout") log = false;
        else if ( s == "private") {
            if(!log) cnt++;
        }
    }
    cout << cnt;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}