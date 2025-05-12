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
    vector<int> v(1<<10,0);
    string s;
    cin >> s;
    ll cur = 0, ans = 0;
    for(int i = 0; i < s.size(); i++){
        int val = s[i]-'0';
        cur^=(1<<val);
        ans+=v[cur];
        if(cur == 0) ans++;
        v[cur]++;
    }
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