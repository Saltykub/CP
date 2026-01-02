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
    string s;
    cin >> n >> s;
    vector<int> cnt;
    vector<int> ans;
    int cur = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            cnt.pb(cur);
            cur = 1;
        }
        else cur++;
    }   
    cnt.pb(cur);
    int nxt = s[0]-'0';
    int prev = 1;
    for(auto u:cnt){
        if(nxt == 0 && u == 1){
            cout << "No\n";
            return;
        }
        if(nxt == 0)  for(int i = prev+u-1; i >= prev; i--) ans.pb(i);
        else for(int i = prev; i < prev+u; i++) ans.pb(i);
        prev += u;
        nxt ^= 1;
    }
    cout << "Yes\n";
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}