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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> ans(q);
    for(auto &u:ans) cin >> u;
    bool can = false;
    for(auto u:s){
        if(u == 'B'){
            can = true;
        }
    }
    if(can){
        for(int i = 0; i < q; i++){
            int j = 0;
            int cnt = 0;
            int u = ans[i];
            while(u){
                if(s[j] == 'A') u--;
                else u/=2;
                cnt++;
                j++;
                j%=n;
            }
            ans[i] = cnt;
        }
    }
    for(auto u:ans) cout << u << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}