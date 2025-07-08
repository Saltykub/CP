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
    vector<int> cnt,ans;
    for(int i = 0; i < 10; i++) cnt.pb(s[i]-'0');
    for(int i = 9; i >= 0; i--){
        sort(cnt.begin(),cnt.end());
        for(int j = 0; j < 10; j++){
            if(cnt[j] >= i){
                ans.pb(cnt[j]);
                cnt[j] = 10;
                break;
            }
        }
    }
    for(auto u:ans) cout << u;
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