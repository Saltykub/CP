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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n == 1){
        cout << '-' << endl;
        return;
    }
    vector<char> ans(n,'+');
    vector<int> cnt(3,0);
    for(auto u:s) {
        cnt[u-'0']++;
    }
     for(int i = cnt[0]; i <= cnt[0]+cnt[2]-1; i++){
        ans[i] = '?';
    }
    for(int i = n-cnt[1]-1; i > n-cnt[1]-cnt[2]-1; i--){
        ans[i] = '?';
    }
    for(int i = 0; i < cnt[0]; i++) ans[i] = '-';
   
    for(int i = n-1; i >= n-cnt[1]; i--) ans[i] = '-';
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