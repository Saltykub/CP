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
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        int cur = s[i]-'0';
        ans += ((cur-ans)%10+10)%10;
    }
    cout << ans + s.size();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}